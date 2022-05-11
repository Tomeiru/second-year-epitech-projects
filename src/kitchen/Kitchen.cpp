/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Kitchen
*/

#include <iostream>
#include "Kitchen.hpp"

void plazza::startKitchen(IProcessCom &com, void *args)
{
    Kitchen kitchen{com, (KitchenConfig*) args};

    kitchen.run();
}

plazza::Kitchen::Kitchen(IProcessCom &com, KitchenConfig *config)
    : _com(com), _config(*config)
{
}

plazza::Kitchen::~Kitchen()
{
}

void plazza::Kitchen::run()
{
    ComType type;
    int bytes_read;

    while (_open) {
        if (_com.canRead()) {
            _com.recv(&type, sizeof(ComType));
            handleCom(type);
        }
    }
}

void plazza::Kitchen::handleCom(ComType type)
{
    switch (type) {
        case PIZZA_TO_COOK:
        break;
        case ASK_KITCHEN_STATE:
        break;
        case CLOSING_KITCHEN:
        _open = false;
        break;
    }
}

void plazza::Kitchen::cookNewPizza()
{
    Serialized serialized;

    if (_com.recv(&serialized, sizeof(Serialized)) != sizeof(Serialized))
        return;
}

void plazza::Kitchen::sendStatus()
{

}
