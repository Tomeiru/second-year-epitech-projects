/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** False
*/

#include "False.hpp"

False::False() : Component("False", 1)
{
    setSinglePin(0, nts::FALSE);
}

False::~False()
{
}