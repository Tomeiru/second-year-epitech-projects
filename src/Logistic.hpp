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

    class Logistic {
        std::unordered_map<uint64_t, std::unique_ptr<CProcess>> _kitchens;
        std::map<uint64_t, KitchenState> _latestStates;
        std::unordered_map<uint8_t, std::chrono::high_resolution_clock::rep> _slackingTime;
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
        void handleResponse(std::unique_ptr<CProcess> &kitchen);
        void updateSlacking();
        void askKitchenStates();

        bool canThisKitchenCookThisPizza(uint64_t kitchenId, const std::unique_ptr<IPizza> &pizza);
        void assignPizzaToKitchen(uint64_t kitchenId, const std::unique_ptr<IPizza> &pizza);

        void toggleStatus();
        void toggleEnd();
        bool getStatus() const;
        bool getEnd() const;
    };
}
