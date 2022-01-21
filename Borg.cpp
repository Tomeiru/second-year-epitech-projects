/*
** EPITECH PROJECT, 2022
** AM
** File description:
** Borg
*/

#include "Borg.hpp"

Borg::Ship::Ship()
{
    _side = 300;
    _maxWarp = 9;
    _location = UNICOMPLEX;
    _home = UNICOMPLEX;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
}

void Borg::Ship::checkCore()
{
    std::string stability;

    if (_core->checkReactor()->isStable() == true)
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (_location == d && _core->checkReactor()->isStable() != true && warp > _maxWarp)
        return (false);
    _location = d;
    return (true);
}

bool Borg::Ship::move(int warp)
{
    if (_location == _home && _core->checkReactor()->isStable() != true && warp > _maxWarp)
        return (false);
    _location = _home;
    return (true);

}

bool Borg::Ship::move(Destination d)
{
    if (_location == d && _core->checkReactor()->isStable() != true)
        return (false);
    _location = d;
    return (true);
}

bool Borg::Ship::move()
{
    if (_location == _home && _core->checkReactor()->isStable() != true)
        return (false);
    _location = _home;
    return (true);
}