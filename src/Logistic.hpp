/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Logistic
*/

#pragma once

#include <vector>
#include <memory>
#include <deque>
#include <map>
#include <unordered_map>
#include <chrono>
#include "Order.hpp"
#include "mutex/CMutex.hpp"
#include "ArgHandler.hpp"
#include "mutex/ScopeLock.hpp"
#include "process/CProcess.hpp"
#include "com/ComProtocol.hpp"

namespace plazza {
    void *logistic_main(void *arg);

    struct LogisticKitchen {
        uint64_t id;
        std::unique_ptr<IProcess> process;
        KitchenState state;
        std::chrono::high_resolution_clock::rep slackTime;
        bool quit;
    };

    class Logistic {
        std::map<uint64_t, LogisticKitchen> _kitchens;
        std::vector<std::unique_ptr<plazza::Order>> _orders;
        plazza::CMutex _ordersLock;
        plazza::CMutex _toggleLock;
        bool _status = false;
        bool _end = false;

        public:
        void addNewOrder(std::unique_ptr<plazza::Order> order);
        unsigned int getQueueSize() const;

        uint64_t createKitchen();
        void closeKitchen(uint64_t id);

        void printKitchenStatus();
        void handleResponses();
        bool handleResponse(LogisticKitchen &kitchen);
        void updateSlacking();
        void askKitchenStates();

        bool canThisKitchenCookThisPizza(uint64_t kitchenId, const std::unique_ptr<IPizza> &pizza);
        void assignPizzaToKitchen(uint64_t kitchenId, const std::unique_ptr<IPizza> &pizza);
        void pizzaHashBeenCooked(LogisticKitchen &kitchen);

        void toggleStatus();
        void toggleEnd();
        bool getStatus() const;
        bool getEnd() const;
    };
}
