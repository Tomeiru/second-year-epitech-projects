/*
** EPITECH PROJECT, 2022
** Day9
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int power) : Peasant::Peasant(name, power), Enchanter(name, power)
{
    std::cout << _Name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << _Name << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (this->getHp() <= 0) {
        std::cout << _Name << " is out of combat." << std::endl;
        return;
    }
    if (this->getPower() < 0) {
        std::cout << _Name << " is out of power." << std::endl;
        return;
    }
    _Power += 100;
    if (_Power > 100)
        _Power = 100;
    _Hp += 100;
    if (_Hp > 100)
        _Hp = 100;
    std::cout << _Name << " prays." << std::endl;
    return;
}
