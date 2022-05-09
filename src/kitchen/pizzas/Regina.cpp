/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Regina
*/

#include "Regina.hpp"

plazza::Regina::Regina(plazza::IPizza::PizzaSize size) : plazza::APizza(size)
{
    _type = REGINA;
    _cookTime = 2;
    _ingredients.push_back(GRUYERE);
    _ingredients.push_back(HAM);
    _ingredients.push_back(MUSHROOMS);
}

plazza::Regina::~Regina()
{
}
