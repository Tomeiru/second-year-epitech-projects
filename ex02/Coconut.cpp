/*
** EPITECH PROJECT, 2022
** Day10B
** File description:
** Coconut
*/

#include "Coconut.hpp"

Coconut::Coconut()
{
    _name = "coconut";
    _vitamins = 15;
}

Coconut::~Coconut()
{
}

std::string Coconut::getName() const
{
    if (this == nullptr)
        return (nullptr);
    return (_name);
}

int Coconut::getVitamins() const
{
    if (this == nullptr)
        return (0);
    return (_vitamins);
}