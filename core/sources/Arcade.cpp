/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade
*/

#include "ArgumentChecker.hpp"

int main(int ac, char **av)
{
    UNUSED(av);
    try {
        ArgumentChecker::CheckNumber(ac);
    }
    catch (ArcadeError const &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
}