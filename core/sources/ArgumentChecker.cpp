/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArgumentChecker
*/

#include "ArgumentChecker.hpp"

void ArgumentChecker::CheckNumber(int ac)
{
    if (ac != 2)
        throw ArcadeError("wrong argument", "wrong number of argument");
}
