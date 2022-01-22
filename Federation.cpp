/*
** EPITECH PROJECT, 2022
** AM
** File description:
** Federation
*/

#include "Federation.hpp"

// Functions from Starfleet Ship

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = maxWarp;
    _location = EARTH;
    _home = EARTH;
    _shield = 100;
    _photonTorpedo = torpedo;
    if (torpedo < 0)
        _photonTorpedo = 0;
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
    if (torpedo != 0)
        std::cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready.";
}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = maxWarp;
    _location = EARTH;
    _home = EARTH;
    _shield = 100;
    _photonTorpedo = 0;
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::Ship()
{
    _length = 289;
    _width = 132;
    _name = "Entreprise";
    _maxWarp = 6;
    _location = EARTH;
    _home = EARTH;
    _shield = 100;
    _photonTorpedo = 0;
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

    if (_core->checkReactor()->isStable() == true)
        stability = "stable";
    else
        stability = "unstable";
    std::cout << "USS " << _name << ": The core is " << stability << " at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    _captain = captain;
    std::cout << _captain->getName() << ": I'm glad to be the captain of the USS " << _name << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (_location == d && _core->checkReactor()->isStable() != true && warp > _maxWarp)
        return (false);
    _location = d;
    return (true);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (_location == _home && _core->checkReactor()->isStable() != true && warp > _maxWarp)
        return (false);
    _location = _home;
    return (true);

}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (_location == d && _core->checkReactor()->isStable() != true)
        return (false);
    _location = d;
    return (true);
}

bool Federation::Starfleet::Ship::move()
{
    if (_location == _home && _core->checkReactor()->isStable() != true)
        return (false);
    _location = _home;
    return (true);
}

int Federation::Starfleet::Ship::getShield()
{
    return (_shield);
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return (_photonTorpedo);
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (_photonTorpedo == 0) {
        std::cout << _name << ": No enough torpedoes to fire," << _captain->getName() << "!" << std::endl;
        return;
    }
    target->setShield(target->getShield() - 50);
    _photonTorpedo = getTorpedo() - 1;
    std::cout << _name << ": Firing on target. " << _photonTorpedo << "torpedoes remaining." << std::endl;
    if (_photonTorpedo == 0)
        std::cout << _name << ": No more torpedo to fire," << _captain->getName() << "!" << std::endl;
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (torpedoes > _photonTorpedo) {
        std::cout << _name << ": No enough torpedoes to fire," << _captain->getName() << "!" << std::endl;
        return;
    }
    target->setShield(target->getShield() - (50 * torpedoes));
    _photonTorpedo = getTorpedo() - torpedoes;
    std::cout << _name << ": Firing on target. " << _photonTorpedo << "torpedoes remaining." << std::endl;
    if (_photonTorpedo == 0)
        std::cout << _name << ": No more torpedo to fire," << _captain->getName() << "!" << std::endl;
}

// Functions from Federation Ship

Federation::Ship::Ship(int length, int width, std::string name)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = 1;
    _location = VULCAN;
    _home = VULCAN;
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

    if (_core->checkReactor()->isStable() == true)
        stability = "stable";
    else
        stability = "unstable";
    std::cout << _name << ": The core is " << stability << " at the time." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (_location == d && _core->checkReactor()->isStable() != true && warp > _maxWarp)
        return (false);
    _location = d;
    return (true);
}

bool Federation::Ship::move(int warp)
{
    if (_location == _home && _core->checkReactor()->isStable() != true && warp > _maxWarp)
        return (false);
    _location = _home;
    return (true);

}

bool Federation::Ship::move(Destination d)
{
    if (_location == d && _core->checkReactor()->isStable() != true)
        return (false);
    _location = d;
    return (true);
}

bool Federation::Ship::move()
{
    if (_location == _home && _core->checkReactor()->isStable() != true)
        return (false);
    _location = _home;
    return (true);
}

// Functions from Captain Class

Federation::Starfleet::Captain::Captain(std::string name)
{
    _name = name;
    _age = 30;
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string Federation::Starfleet::Captain::getName()
{
    return (_name);
}

int Federation::Starfleet::Captain::getAge()
{
    return (_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

// Functions from Ensign Class

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    _name = name;
    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}