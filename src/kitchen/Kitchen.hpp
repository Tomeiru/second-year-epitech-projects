/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Kitchen
*/

#pragma once

#include "../com/IProcessCom.hpp"
#include "../com/ComProtocol.hpp"
#include "./pizzas/IPizza.hpp"
#include "./pizzas/Serializer.hpp"

namespace plazza {
    void startKitchen(IProcessCom &com, void *args);

    class Kitchen {
        IProcessCom &_com;
        KitchenConfig &_config;
        bool _open = true;

        using Serialized = Serializer::PizzaSerialized;

        public:
            Kitchen(IProcessCom &com, KitchenConfig *config);
            ~Kitchen();
            void run();
            void handleCom(ComType type);
            void cookNewPizza();
            void sendStatus();
    };
}
