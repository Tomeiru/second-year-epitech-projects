/*
** EPITECH PROJECT, 2022
** Day10
** File description:
** Lemon
*/

#include "Lemon.hpp"

Lemon::Lemon()
{
    _name = "lemon";
    _vitamins = 3;
}

Lemon::~Lemon()
{
}

std::string Lemon::getName() const
{
    if (this == nullptr)
        return (nullptr);
    return (_name);
}

int Lemon::getVitamins() const
{
    if (this == nullptr)
        return (0);
    return (_vitamins);
}