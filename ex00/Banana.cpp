/*
** EPITECH PROJECT, 2022
** Day10
** File description:
** Banana
*/

#include "Banana.hpp"

Banana::Banana()
{
    _name = "banana";
    _vitamins = 5;
}

Banana::~Banana()
{
}

std::string Banana::getName() const
{
    if (this == nullptr)
        return (nullptr);
    return (_name);
}

int Banana::getVitamins() const
{
    if (this == nullptr)
        return (0);
    return (_vitamins);
}