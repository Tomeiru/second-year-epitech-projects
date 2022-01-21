/*
** EPITECH PROJECT, 2022
** AM
** File description:
** Federation
*/

#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = maxWarp;
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::string stability;

    if (_core->_coreReactor->isStable() == true)
        stability = "stable";
    else
        stability = "unstable";
    std::cout << "USS " << _name << ": The core is " << stability << " at the time." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
    _length = length;
    _width = width;
    _name = name;
    std::cout << "The independent ship " << _name << " just finished its construction." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{

}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    std::string stability;

    if (_core->_coreReactor->isStable() == true)
        stability = "stable";
    else
        stability = "unstable";
    std::cout << _name << ": The core is " << stability << " at the time." << std::endl;
}