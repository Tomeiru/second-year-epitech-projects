/*
** EPITECH PROJECT, 2022
** Day9
** File description:
** Peasant
*/

#include "Peasant.hpp"

Peasant::Peasant(const std::string &name, int power)
{
    _Name = name;
    _Power = power;
    _Hp = 100;

    std::cout << _Name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << _Name << " is back to his crops." << std::endl;
}

const std::string &Peasant::getName() const
{
    return (_Name);
}

int Peasant::getPower() const
{
    return (_Power);
}

int Peasant::getHp() const
{
    return (_Hp);
}

int Peasant::attack()
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
    std::cout << _Name << " tosses a stone." << std::endl;
    return (5);
}

int Peasant::special()
{
    if (this->getHp() <= 0) {
        std::cout << _Name << " is out of combat." << std::endl;
        return (0);
    }
    if (this->getPower() < 0) {
        std::cout << _Name << " is out of power." << std::endl;
        return (0);
    }
    std::cout << _Name << " doesn't know any special move." << std::endl;
    return (0);
}

void Peasant::rest()
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
    std::cout << _Name << " takes a nap." << std::endl;
    return;
}

void Peasant::damage(int damage)
{
    if (_Hp <= 0) {
        std::cout << _Name << " is out of combat." << std::endl;
        return;
    }
    _Hp -= damage;
    if (_Hp > 0) {
        std::cout << _Name << " takes " << damage << " damage." << std::endl;
        return;
    }
    std::cout << _Name << " is out of combat." << std::endl;


}
