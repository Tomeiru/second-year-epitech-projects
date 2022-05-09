/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <sstream>
#include <regex>
#include <string>
#include "kitchen/pizzas/APizza.hpp"

class Reception {
    public:
        Reception();
        ~Reception();
        void console();
        void getInput();
        void handleInput();
        bool checkEmpty();
        std::string removeSpacesBeforeAndAfter(std::string);
        void handleOrders();
    protected:
        std::string _input;
        std::string _delims;
        std::vector<std::unique_ptr<plazza::IPizza>> _order;
    private:
};

#endif /* !RECEPTION_HPP_ */
