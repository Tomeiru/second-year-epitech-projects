/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Kitchen
*/

#pragma once

#include <unordered_map>
#include "../com/IProcessCom.hpp"
#include "../com/ComProtocol.hpp"
#include "./pizzas/IPizza.hpp"
#include "./pizzas/Serializer.hpp"
#include "../thread/ThreadPool.hpp"
#include "../mutex/CMutex.hpp"
#include "../mutex/ScopeLock.hpp"

namespace plazza {
    using Serialized = Serializer::PizzaSerialized;

    void startKitchen(IProcessCom &com, void *args);

    class Kitchen {
        IProcessCom &_com;
        KitchenConfig &_config;
        bool _open = true;
        ThreadPool _pool;
        std::unordered_map<IPizza::Ingredient, size_t> _ingredients;
        uint _pizzaWaiting = 0;
        uint _pizzaBeingCooked = 0;
        CMutex _cookingLock;

        public:
            Kitchen(IProcessCom &com, KitchenConfig *config);
            ~Kitchen() = default;

            void run();
            void handleCom(ComType type);
            void cookNewPizza();
            void sendStatus();

            void pizzaStartBeingCooked(std::unique_ptr<IPizza> &pizza);
            void pizzaHasBeenCooked(std::unique_ptr<IPizza> &pizza);

            const KitchenConfig &getConfig() { return _config; };
    };

    class CookPizzaJob : public IJob {
        Kitchen &_kitchen;
        std::unique_ptr<IPizza> _pizza;

        public:
        CookPizzaJob(Kitchen &kitchen, std::unique_ptr<IPizza> &pizza)
            : _kitchen(kitchen), _pizza(std::move(pizza)) {};

        void execute()
        {
            _kitchen.pizzaStartBeingCooked(_pizza);
            CThread::sleep(_pizza->getCookTime() * _kitchen.getConfig().cookFactor);
            _kitchen.pizzaHasBeenCooked(_pizza);
        };
    };

}
