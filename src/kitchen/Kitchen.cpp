/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Kitchen
*/

#include <chrono>
#include <iostream>
#include "Kitchen.hpp"

void plazza::startKitchen(IProcessCom &com, void *args)
{
    Kitchen kitchen{com, (KitchenConfig*) args};

    kitchen.run();
}

plazza::Kitchen::Kitchen(IProcessCom &com, KitchenConfig *config)
    : _com(com), _config(*config), _pool{config->nbCooks}
{
    for (size_t i = 0; i < IPizza::MAX_INGREDIENT; i += 1)
        _ingredients.insert({(IPizza::Ingredient) i, 5});
}

void plazza::Kitchen::run()
{
    ComType type;
    int bytes_read;

    while (_open) {
        _com.recv(&type, sizeof(ComType));
        handleCom(type);
    }
}

void plazza::Kitchen::handleCom(ComType type)
{
    switch (type) {
        case PIZZA_TO_COOK:
        cookNewPizza();
        break;
        case ASK_KITCHEN_STATE:
        sendStatus();
        break;
        case CLOSING_KITCHEN:
        _open = false;
        break;
    }
}

void plazza::Kitchen::cookNewPizza()
{
    ScopeLock{(IMutex&) _cookingLock};
    Serialized serialized;
    std::unique_ptr<IPizza> pizza;
    std::unique_ptr<CookPizzaJob> job;

    if (_com.recv(&serialized, sizeof(Serialized)) != sizeof(Serialized))
        return;
    pizza = Serializer::deserialize(serialized);
    for (IPizza::Ingredient ingredient : pizza->getIngredients())
        _ingredients[ingredient]--;
    job = std::make_unique<CookPizzaJob>(*this, pizza);
    _pool.addJob((std::unique_ptr<Job>&) job);
    _pizzaWaiting++;
}

void plazza::Kitchen::pizzaStartBeingCooked(std::unique_ptr<IPizza> &pizza)
{
    ScopeLock{(IMutex&) _cookingLock};

    (void) pizza;
    _pizzaWaiting--;
    _pizzaBeingCooked++;
}

void plazza::Kitchen::pizzaHasBeenCooked(std::unique_ptr<IPizza> &pizza)
{
    ScopeLock{(IMutex&) _cookingLock};

    _pizzaBeingCooked--;
}

void plazza::Kitchen::sendStatus()
{
    ScopeLock{(IMutex&) _cookingLock};
    KitchenStateHeader header;
    uint tmp;

    header.nbPizzasWaitingToBeCooked = _pizzaWaiting;
    header.nbPizzasBeignCooked = _pizzaBeingCooked;
    _com.send(&header, sizeof(KitchenStateHeader));
    for (size_t i = 0; i < IPizza::MAX_INGREDIENT; i += 1) {
        tmp = _ingredients[(IPizza::Ingredient) i];
        _com.send(&tmp, sizeof(uint));
    }
}
