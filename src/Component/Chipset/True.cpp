/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** True
*/

#include "True.hpp"

True::True() : Component("True", 1)
{
}

True::~True()
{
}

void True::simulate(std::size_t tick)
{
    UNUSED(tick);
    setSinglePin(0, nts::Tristate::TRUE);
}