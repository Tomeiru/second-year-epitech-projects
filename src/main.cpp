/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** Main
*/

#include "MyGKrellm.hpp"

int main(int ac, char **av)
{
    try {
        argumentCheck(ac, av);
    }
    catch (std::exception const &error) {
        std::cerr << error.what() << std::endl;
    }
}
