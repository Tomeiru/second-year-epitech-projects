/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Logistic
*/

#include "Logistic.hpp"
#include "com/ComProtocol.hpp"
#include "kitchen/Kitchen.hpp"

void *plazza::logistic_main(void *arg)
{
    Logistic *logistic = (Logistic*) arg;

    while (true) {
        CThread::sleep(0.1);
        if (logistic->getEnd())
            break;
        logistic->handleResponses();
        logistic->updateSlacking();
        if (logistic->getStatus()) {
            logistic->toggleStatus();
            logistic->printKitchenStatus();
        }
        logistic->askKitchenStates();
    }
    return (nullptr);
}

plazza::Logistic::Logistic(std::tuple<double,int,int> arg)
{
    _multiplier = std::get<0>(arg);
    _nbCooks = std::get<1>(arg);
    _stockTime = std::get<2>(arg);
}

void plazza::Logistic::printKitchenStatus()
{
    std::cout << "Open kitchens : " << _kitchens.size() << std::endl;
    for (auto &[id, kitchen] : _kitchens) {
        std::cout << "Kitchen #" << id << "\n";
        std::cout << "Pizzas being cooked: " << kitchen.state.nbPizzasBeignCooked << "\n";
        std::cout << "Pizzas waiting to be cooked: " << kitchen.state.nbPizzasWaitingToBeCooked << "\n";
        std::cout << "Ingredients:\n";
        for (std::size_t i = 0; i < IPizza::MAX_INGREDIENT; i++)
            std::cout << "\t" << APizza::ingredientToString((IPizza::Ingredient) i) << ": " << kitchen.state.stocks[i] << "\n";
        std::cout << std::endl;
    }
}

void plazza::Logistic::handleResponses()
{
    std::vector<uint64_t> toBeDeleted;

    for (auto &[id, kitchen] : _kitchens) {
        while (kitchen.process->getCom().canRead()) {
            if (handleResponse(kitchen)) {
                toBeDeleted.push_back(id);
                break;
            }
        }
    }
    for (uint64_t id : toBeDeleted)
        closeKitchen(id);
}

bool plazza::Logistic::handleResponse(LogisticKitchen &kitchen)
{
    ComType type = UNDEF_COM;
    KitchenState state;
    size_t read = kitchen.process->getCom().recv(&type, sizeof(ComType));

    if (read == 0)
        return true;
    switch (type) {
        case PIZZA_COOKED:
        pizzaHashBeenCooked(kitchen);
        break;
        case SEND_KITCHEN_STATE:
        kitchen.process->getCom().recv(&state, sizeof(KitchenState));
        _kitchens[state.kitchenId].state = state;
        break;
        default:
        throw std::runtime_error(std::string("Invalid ComType received : ") + std::to_string(type));
        break;
    }
    return false;
}

void plazza::Logistic::pizzaHashBeenCooked(LogisticKitchen &kitchen)
{
    Serialized pizzaData;
    std::unique_ptr<IPizza> pizza;

    kitchen.process->getCom().recv(&pizzaData, sizeof(Serialized));
    pizza = Serializer::deserialize(pizzaData);
    std::cout << "Pizza #" << pizza->getId() << " '" << pizza->getStringType() << " " << pizza->getStringSize() << "' has been cooked !" << std::endl;
    for (auto i = _orders.begin(); i != _orders.end(); i++) {
        if (i->get()->isPizzaInThisOrder(pizzaData.id)) {
            i->get()->addPizzaCooked(pizzaData.id);
            if (i->get()->checkCompletion()) {
                i->get()->printCompletion();
                _orders.erase(i);
            }
            break;
        }
    }
}

void plazza::Logistic::updateSlacking()
{
    std::chrono::high_resolution_clock::rep now = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    for (auto &[id, kitchen] : _kitchens) {
        if (kitchen.quit)
            continue;
        if (kitchen.state.nbPizzasBeignCooked == 0 && kitchen.state.nbPizzasWaitingToBeCooked == 0) {
            if (now - kitchen.slackTime >= 5000000000) {
                kitchen.quit = true;
                sendData(kitchen.process->getCom(), CLOSING_KITCHEN, nullptr, 0);
            }
        } else
            kitchen.slackTime = now;
    }
}

uint64_t plazza::Logistic::createKitchen()
{
    static uint64_t id = 0;
    KitchenConfig config;
    std::unique_ptr<IProcess> kitchen;
    KitchenState state;

    std::cout << "Open kitchen " << id << std::endl;
    config.kitchenId = id;
    config.cookFactor = _multiplier;
    config.refillTimer = _stockTime;
    config.nbCooks = _nbCooks;
    state.kitchenId = id;
    state.nbPizzasBeignCooked = 0;
    state.nbPizzasWaitingToBeCooked = 0;
    for (std::size_t i = 0; i < IPizza::MAX_INGREDIENT; i++)
        state.stocks[i] = 5;
    kitchen = std::make_unique<CProcess>(startKitchen, &config);
    _kitchens[id] = std::move((LogisticKitchen) {
        id,
        std::move(kitchen),
        state,
        std::chrono::high_resolution_clock::now().time_since_epoch().count(),
        false,
    });
    id++;
    return config.kitchenId;
}

void plazza::Logistic::closeKitchen(uint64_t id)
{
    LogisticKitchen &kitchen = _kitchens[id];

    std::cout << "Close kitchen " << id << std::endl;
    kitchen.process->getCom().closeCom();
    kitchen.process->close();
    _kitchens.erase(id);
}

void plazza::Logistic::askKitchenStates()
{
    for (auto &[id, kitchen] : _kitchens)
        sendData(kitchen.process->getCom(), ASK_KITCHEN_STATE, nullptr, 0);
}

void plazza::Logistic::addNewOrder(std::unique_ptr<plazza::Order> order)
{
    ScopeLock lock{(IMutex&) _ordersLock};
    bool assigned = false;
    uint64_t id;

    for (const std::unique_ptr<IPizza> &pizza : order->getPizzas()) {
        assigned = false;
        for (auto &[id, kitchen] : _kitchens) {
            if (canThisKitchenCookThisPizza(id, pizza)) {
                assignPizzaToKitchen(id, pizza);
                assigned = true;
                break;
            }
        }
        if (!assigned) {
            id = createKitchen();
            assignPizzaToKitchen(id, pizza);
        }
    }
    _orders.push_back(std::move(order));
}

bool plazza::Logistic::canThisKitchenCookThisPizza(uint64_t kitchenId, const std::unique_ptr<IPizza> &pizza)
{
    KitchenState &state = _kitchens[kitchenId].state;

    if (_kitchens[kitchenId].quit)
        return false;
    if (state.nbPizzasBeignCooked + state.nbPizzasWaitingToBeCooked == _nbCooks * 2)
        return false;
    for (IPizza::Ingredient ingredient : pizza->getIngredients()) {
        if (state.stocks[ingredient] == 0)
            return false;
    }
    return true;
}

void plazza::Logistic::assignPizzaToKitchen(uint64_t kitchenId, const std::unique_ptr<IPizza> &pizza)
{
    Serialized data = Serializer::serialize(*pizza.get());
    KitchenState &state = _kitchens[kitchenId].state;

    state.nbPizzasWaitingToBeCooked++;
    for (IPizza::Ingredient ingredient : pizza->getIngredients())
        state.stocks[ingredient]--;
    sendData(_kitchens[kitchenId].process->getCom(), PIZZA_TO_COOK, &data, sizeof(Serialized));
}

unsigned int plazza::Logistic::getQueueSize() const
{
    ScopeLock lock{(IMutex&) _ordersLock};

    if (_orders.empty())
        return (0);
    return (_orders.size());
}

void plazza::Logistic::toggleStatus()
{
    ScopeLock lock{(IMutex&) _toggleLock};

    _status = (_status ? false : true);
}

void plazza::Logistic::toggleEnd()
{
    ScopeLock lock{(IMutex&) _toggleLock};

    _end = (_status ? false : true);
}

bool plazza::Logistic::getStatus() const
{
    ScopeLock lock{(IMutex&) _toggleLock};

    return (_status);
}

bool plazza::Logistic::getEnd() const
{
    ScopeLock lock{(IMutex&) _toggleLock};

    return (_end);
}
