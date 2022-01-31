/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** argumentCheck
*/

#include "MyGKrellm.hpp"

void argumentCheck(int ac, char **av)
{
    if (ac != 2)
        throw std::invalid_argument ("Wrong amount of arguments!");
    if (strcmp(av[1], "text") != 0 && strcmp(av[1], "graphical") != 0)
        throw std::invalid_argument ("Argument doesn't match 'text' or 'graphical'!");
}