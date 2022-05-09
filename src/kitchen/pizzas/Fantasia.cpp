/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Fantasia
*/

#include "Fantasia.hpp"

plazza::Fantasia::Fantasia(plazza::IPizza::PizzaSize size) : plazza::APizza(size)
{
    _type = FANTASIA;
    _cookTime = 4;
    _ingredients.push_back(EGGPLANT);
    _ingredients.push_back(GOAT_CHEESE);
    _ingredients.push_back(CHIEF_LOVE);
}

plazza::Fantasia::~Fantasia()
{
}
