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

void plazza::Logistic::printKitchenStatus()
{
    for (auto &[id, state] : _latestStates) {
        std::cout << "Kitchen #" << id << "\n";
        std::cout << "Pizzas being cooked: " << state.nbPizzasBeignCooked << "\n";
        std::cout << "Pizzas waiting to be cooked: " << state.nbPizzasWaitingToBeCooked << "\n";
        std::cout << "Ingredients:\n";
        for (std::size_t i = 0; i < IPizza::MAX_INGREDIENT; i++)
            std::cout << "\t" << APizza::ingredientToString((IPizza::Ingredient) i) << ": " << state.stocks[i] << "\n";
        std::cout << std::endl;
    }
}

void plazza::Logistic::handleResponses()
{
    for (auto &[id, kitchen] : _kitchens) {
        while (kitchen->getCom().canRead())
            handleResponse(kitchen);
    }
}

// TODO : CHECK ORDER COMPLETION
void plazza::Logistic::handleResponse(std::unique_ptr<IProcess> &kitchen)
{
    ComType type;
    KitchenState state;
    Serialized pizzaData;

    kitchen->getCom().recv(&type, sizeof(ComType));
    switch (type) {
        case PIZZA_COOKED:
        kitchen->getCom().recv(&pizzaData, sizeof(Serialized));
        for (std::unique_ptr<Order> &order : _orders) {
            if (order->isPizzaInThisOrder(pizzaData.id)) {
                order->addPizzaCooked(pizzaData.id);
                break;
            }
        }
        break;
        case SEND_KITCHEN_STATE:
        kitchen->getCom().recv(&state, sizeof(KitchenState));
        _latestStates[state.kitchenId] = state;
        break;
    }
}

void plazza::Logistic::updateSlacking()
{
    std::chrono::high_resolution_clock::rep now = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::vector<size_t> toBeClosed;

    for (auto &[id, state] : _latestStates) {
        if (state.nbPizzasBeignCooked == 0 && state.nbPizzasWaitingToBeCooked == 0) {
            if (now - _slackingTime[id] >= 5000000000)
                toBeClosed.push_back(id);
        } else
            _slackingTime[id] = now;
    }
    for (size_t id : toBeClosed)
        closeKitchen(id);
}

// TODO : CHANGE THIS TO ARGS GIVEN
uint64_t plazza::Logistic::createKitchen()
{
    static uint64_t id = 0;
    KitchenConfig config;
    std::unique_ptr<IProcess> kitchen;
    KitchenState state;

    std::cout << "Open kitchen " << id << std::endl;
    config.kitchenId = id;
    config.cookFactor = 1;
    config.refillTimer = 1000;
    config.nbCooks = 3;
    state.kitchenId = id;
    state.nbPizzasBeignCooked = 0;
    state.nbPizzasWaitingToBeCooked = 0;
    for (std::size_t i = 0; i < IPizza::MAX_INGREDIENT; i++)
        state.stocks[i] = 5;
    kitchen = std::make_unique<CProcess>(startKitchen, &config);
    _kitchens[id] = std::move(kitchen);
    _slackingTime[id] = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    _latestStates[id] = state;
    id++;
    return config.kitchenId;
}

void plazza::Logistic::closeKitchen(uint64_t id)
{
    std::unique_ptr<IProcess> &kitchen = _kitchens[id];

    std::cout << "Close kitchen " << id << std::endl;
    sendData(kitchen->getCom(), CLOSING_KITCHEN, nullptr, 0);
    _kitchens.erase(id);
    _slackingTime.erase(id);
    _latestStates.erase(id);
}

void plazza::Logistic::askKitchenStates()
{
    for (auto &[id, kitchen] : _kitchens)
        sendData(kitchen->getCom(), ASK_KITCHEN_STATE, nullptr, 0);
}

void plazza::Logistic::addNewOrder(std::unique_ptr<plazza::Order> order)
{
    ScopeLock{(IMutex&) _ordersLock};
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

// TODO : USE ARGS GIVEN
bool plazza::Logistic::canThisKitchenCookThisPizza(uint64_t kitchenId, const std::unique_ptr<IPizza> &pizza)
{
    KitchenState state = _latestStates[kitchenId];

    if (state.nbPizzasBeignCooked + state.nbPizzasWaitingToBeCooked == 6 * 2)
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

    _latestStates[kitchenId].nbPizzasWaitingToBeCooked++;
    for (IPizza::Ingredient ingredient : pizza->getIngredients())
        _latestStates[kitchenId].stocks[ingredient]--;
    sendData(_kitchens[kitchenId]->getCom(), PIZZA_TO_COOK, &data, sizeof(Serialized));
}

unsigned int plazza::Logistic::getQueueSize() const
{
    ScopeLock{(IMutex&) _ordersLock};

    if (_orders.empty())
        return (0);
    return (_orders.size());
}

void plazza::Logistic::toggleStatus()
{
    ScopeLock{(IMutex&) _toggleLock};

    _status = (_status ? false : true);
}

void plazza::Logistic::toggleEnd()
{
    ScopeLock{(IMutex&) _toggleLock};

    _end = (_status ? false : true);
}

bool plazza::Logistic::getStatus() const
{
    ScopeLock{(IMutex&) _toggleLock};

    return (_status);
}

bool plazza::Logistic::getEnd() const
{
    ScopeLock{(IMutex&) _toggleLock};

    return (_end);
}
