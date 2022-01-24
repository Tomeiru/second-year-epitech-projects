/*
** EPITECH PROJECT, 2022
** Day9
** File description:
** Enchanter
*/

#include "Enchanter.hpp"

Enchanter::Enchanter(const std::string &name, int power) : Peasant::Peasant(name, power)
{
    std::cout << _Name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << _Name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
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
    std::cout << _Name << " doesn't know how to fight." << std::endl;
    return (0);
}

int Enchanter::special()
{
    if (this->getHp() <= 0) {
        std::cout << _Name << " is out of combat." << std::endl;
        return (0);
    }
    if (this->getPower() < 50) {
        std::cout << _Name << " is out of power." << std::endl;
        return (0);
    }
    this->_Power -= 50;
    std::cout << _Name << " casts a fireball." << std::endl;
    return (99);
}

void Enchanter::rest()
{
    if (this->getHp() <= 0) {
        std::cout << _Name << " is out of combat." << std::endl;
        return;
    }
    if (this->getPower() < 0) {
        std::cout << _Name << " is out of power." << std::endl;
        return;
    }
    _Power += 50;
    if (_Power > 100)
        _Power = 100;
    std::cout << _Name << " meditates." << std::endl;
    return;
}
