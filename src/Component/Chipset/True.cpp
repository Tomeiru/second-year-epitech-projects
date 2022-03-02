/*
** EPITECH PROJECT, 2022
** PGE2
** File description:
** True
*/

#include "True.hpp"

True::True() : Component("True", 1)
{
    setSinglePin(0, nts::TRUE);
}

True::~True()
{
}