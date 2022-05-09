/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** Margarita
*/

#include "Margarita.hpp"

plazza::Margarita::Margarita(plazza::IPizza::PizzaSize size) : plazza::APizza(size)
{
    _ingredients.push_back(GRUYERE);
}

plazza::Margarita::~Margarita()
{
}
