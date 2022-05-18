/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** ComStructures
*/

#pragma once

#include "IProcessCom.hpp"
#include "../kitchen/pizzas/IPizza.hpp"

namespace plazza {
    enum ComType : unsigned char {
        PIZZA_TO_COOK = 1,
        PIZZA_COOKED = 2,
        ASK_KITCHEN_STATE = 3,
        SEND_KITCHEN_STATE = 4,
        CLOSING_KITCHEN = 5,
        UNDEF_COM = 255,
    };

    typedef struct KitchenConfig_s {
        unsigned int kitchenId;
        unsigned int nbCooks;
        float cookFactor;
        unsigned int refillTimer;
    } KitchenConfig;

    typedef struct KitchenState_s {
        unsigned int kitchenId;
        unsigned int nbPizzasBeignCooked;
        unsigned int nbPizzasWaitingToBeCooked;
        size_t stocks[IPizza::MAX_INGREDIENT];
    } KitchenState;

    inline void sendData(IProcessCom &com, ComType type, void *data, size_t size)
    {
        char buf[sizeof(ComType) + size];

        for (size_t i = 0; i < sizeof(ComType); i++)
            buf[i] = ((char*) &type)[i];
        for (size_t i = 0; i < size; i++)
            buf[sizeof(ComType) + i] = ((char*) data)[i];
        // std::cout << "SEND " << std::to_string(type) << std::endl;
        com.send(&buf, sizeof(ComType) + size);
    }
}
