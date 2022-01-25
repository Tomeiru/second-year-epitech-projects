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
    return (_name);
}

int Fruit::getVitamins() const
{
    return (_vitamins);
}
