/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** False
*/

#include "False.hpp"

False::False(std::string name) : Component("False", 1)
{
}

False::~False()
{
}

void False::simulate(std::size_t tick)
{
    UNUSED(tick);
    setSinglePin(0, nts::Tristate::FALSE);
}