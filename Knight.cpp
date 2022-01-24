/*
** EPITECH PROJECT, 2022
** Day9
** File description:
** Knight
*/

#include "Knight.hpp"

Knight::Knight(const std::string &name, int power) : Peasant::Peasant(name, power)
{
    std::cout << _Name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << _Name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    if (this->getHp() <= 0) {
        std::cout << _Name << " is out of combat." << std::endl;
        return (0);
    }
    if (this->getPower() < 10) {
        std::cout << _Name << " is out of power." << std::endl;
        return (0);
    }
    this->_Power -= 10;
    std::cout << _Name << " strikes with his sword." << std::endl;
    return (20);
}

int Knight::special()
{
    if (this->getHp() <= 0) {
        std::cout << _Name << " is out of combat." << std::endl;
        return (0);
    }
    if (this->getPower() < 30) {
        std::cout << _Name << " is out of power." << std::endl;
        return (0);
    }
    std::cout << _Name << " impales his enemy." << std::endl;
    return (50);
}

void Knight::rest()
{
    if (this->getHp() <= 0) {
        std::cout << _Name << " is out of combat." << std::endl;
        return;
    }
    if (this->getPower() < 0) {
        std::cout << _Name << " is out of power." << std::endl;
        return;
    }
    _Power += 30;
    std::cout << _Name << " eats." << std::endl;
    return;
}
