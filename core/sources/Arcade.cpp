/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade
*/

#include "ArgumentChecker.hpp"

int main(int ac, char **av)
{
    void *lib = NULL;

    try {
        ArgumentChecker::CheckNumber(ac);
        lib = ArgumentChecker::CheckAndOpenLibrary(av[1]);
    }
    catch (ArcadeError const &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
}