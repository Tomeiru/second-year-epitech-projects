/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade
*/

#include "Arcade.hpp"

Arcade::Arcade()
{
    _dlGame = NULL;
    _dlGraphical = NULL;
}

Arcade::~Arcade()
{
}

void Arcade::changeLibraryByPath(std::string path, bool graphical)
{
    if (graphical) {
        closeDl(true);
        _dlGraphical = dlopen(path.c_str(), RTLD_LAZY);
        initClassFromDl(true);
        return;
    }
    if (_dlGame != NULL)
        closeDl(false);
    _dlGame = dlopen(path.c_str(), RTLD_LAZY);
    initClassFromDl(false);
}

void Arcade::setDlGraphical(void *dlGraphical)
{
    _dlGraphical = dlGraphical;
}

void Arcade::initClassFromDl(bool graphical)
{
    std::unique_ptr<IDisplayModule> (*displayHandle)(void);
    std::unique_ptr<IGameModule> (*gameHandle)(void);

    if (graphical) {
        *(void **) &displayHandle = dlsym(_dlGraphical, "gEpitechArcadeGetDisplayModuleHandle");
        _graphical = (*displayHandle)();
        return;
    }
    *(void **) &gameHandle = dlsym(_dlGame, "gEpitechArcadeGetGameModuleHandle");
    _game = (*gameHandle)();
}

void Arcade::closeDl(bool graphical)
{
    if (graphical) {
        _graphical = nullptr;
        dlclose(_dlGraphical);
        return;
    }
    _game = nullptr;
    dlclose(_dlGame);
}

void Arcade::mainMenu(void)
{
    _graphical->openWindow((IDisplayModule::Vector2u){0, 0});
    //getInput
}