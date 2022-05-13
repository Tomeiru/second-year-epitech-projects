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
#include "kitchen/pizzas/APizza.hpp"
#include "thread/CThread.hpp"

class Reception {
    public:
        Reception(std::vector<std::unique_ptr<plazza::IPizza>> *queue);
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
        std::vector<std::unique_ptr<plazza::IPizza>> _order;
        std::vector<std::unique_ptr<plazza::IPizza>> *_queue;
    private:
};
