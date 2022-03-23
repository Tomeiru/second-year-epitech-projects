/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade
*/

#include "Arcade.hpp"

int main(int ac, char **av)
{
    Arcade game;

    try {
        ArgumentChecker::CheckNumber(ac);
        game.setDlGraphical(ArgumentChecker::CheckAndOpenLibrary(av[1]));
        game.initClassFromDl(true);
        game.mainMenu();
        game.closeDl(true);
    }
    catch (ArcadeError const &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
}