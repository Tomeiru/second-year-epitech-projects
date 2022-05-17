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

namespace plazza {
    class Reception {
        std::string _input = "";
        std::string _delims = " \t";
        std::unique_ptr<plazza::Order> _order = nullptr;
        std::vector<std::unique_ptr<plazza::IPizza>> _pizzas;
        Logistic *_logistic;

        public:
            Reception(Logistic *logistic) : _logistic(logistic) {};
            ~Reception() = default;

            void console();
            void getInput();
            void handleInput();
            bool checkEmpty();
            std::string removeSpacesBeforeAndAfter(std::string);
            void handleOrders();
            void *handleReceivedPizza(void *arg);
    };
}
