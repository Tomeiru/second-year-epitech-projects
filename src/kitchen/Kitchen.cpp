/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

plazza::Kitchen::Kitchen(unsigned int cookNbr)
    : _cookNbr(cookNbr)
{
    for (unsigned int i = 0; i != cookNbr; i++) {
        Cook cook;
        _cooks.push_back(cook);
    }
}

plazza::Kitchen::~Kitchen()
{
}
