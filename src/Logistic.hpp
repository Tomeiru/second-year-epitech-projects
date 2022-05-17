/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Logistic
*/

#pragma once

#include <vector>
#include <memory>
#include "Order.hpp"
#include "mutex/CMutex.hpp"
#include "ArgHandler.hpp"

class Logistic {
    public:
        Logistic();
        ~Logistic();
        void pushBackQueue(std::unique_ptr<plazza::Order> order);
        unsigned int getQueueSize() const;
        void toggleStatus();
        void toggleEnd();
        bool getStatus() const;
        bool getEnd() const;
        void lockMutex();
        void unlockMutex();

    protected:
        std::vector<std::unique_ptr<plazza::Order>> _queue;
        bool _status;
        bool _end;
        plazza::CMutex _mutex;
    private:
};
