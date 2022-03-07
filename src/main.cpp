/*
** EPITECH PROJECT, 2022
** 202unsold
** File description:
** main
*/

#include "Error.hpp"

void checkArg(int ac, char **av)
{
    if (ac == 2 && strcmp("-h", av[1]) == 0)
        throw UnsoldError("Usage");
    if (ac != 3)
        throw UnsoldError("Wrong number of arg");
}

int main(int ac, char **av)
{
    try {
        checkArg(ac, av);
        Unsold unsold(av[1], av[2]);
        unsold.Calculate();
        unsold.PrintUnsold();
    }
    catch (UnsoldError const &error) {
        std::ifstream f("usage");
        if (strcmp(error.what(), "Usage") == 0) {
            if (f.is_open())
                std::cout << f.rdbuf();
            return (0);
        }
        if (f.is_open())
            std::cerr << f.rdbuf();
        return (84);
    }
}