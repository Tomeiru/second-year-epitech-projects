/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** Main
*/

#include "MyGKrellmInfo.hpp"

int main(int ac, char **av)
{
    try {
        argumentCheck(ac, av);
    }
    catch (std::exception const &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    MyGKrellmInfo infos;
    if (strcmp(av[1], "text") == 0)
        startCurses(&infos);
    else
        startSFML(&infos);
}
