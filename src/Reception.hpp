/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Reception
*/

#pragma once

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <sstream>
#include <regex>
#include <string>
#include <unistd.h>
#include "Order.hpp"
#include "thread/CThread.hpp"
#include "Logistic.hpp"

class Reception {
    public:
        Reception(Logistic *queue);
        ~Reception();
        void console();
        void getInput();
        void handleInput();
        bool checkEmpty();
        std::string removeSpacesBeforeAndAfter(std::string);
        void handleOrders();
        void *handleReceivedPizza(void *arg);
    protected:
        std::string _input;
        std::string _delims;
        std::unique_ptr<plazza::Order> _order;
        std::vector<std::unique_ptr<plazza::IPizza>> _pizzas;
        Logistic *_logistic;
    private:
};
