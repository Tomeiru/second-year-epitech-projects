/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Americana
*/

#include "Americana.hpp"

plazza::Americana::Americana(plazza::IPizza::PizzaSize size) : plazza::APizza(size)
{
    _type = AMERICANA;
    _cookTime = 2;
    _ingredients.push_back(GRUYERE);
    _ingredients.push_back(STEAK);
}

plazza::Americana::~Americana()
{
}
