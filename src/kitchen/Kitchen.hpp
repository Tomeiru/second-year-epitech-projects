/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Kitchen
*/

#pragma once

#include "Cook.hpp"
#include <deque>
#include <iostream>

namespace plazza {
    class Kitchen {
        unsigned int _cookNbr;
        std::deque<Cook> _cooks;

        public:
            Kitchen(unsigned int cookNbr);
            ~Kitchen();
    };
}
