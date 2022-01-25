/*
** EPITECH PROJECT, 2022
** Day10
** File description:
** Fruit
*/

#include "Fruit.hpp"

/*Fruit::Fruit(std::string name, int vitamins)
{
    _name = name;
    _vitamins = vitamins;
}

Fruit::Fruit()
{
}*/

Fruit::~Fruit()
{
}

std::string Fruit::getName() const
{
    if (this == nullptr)
        return (nullptr);
    return (_name);
}

int Fruit::getVitamins() const
{
    if (this == nullptr)
        return (0);
    return (_vitamins);
}
