/*
** EPITECH PROJECT, 2022
** Day9
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int power) : Peasant::Peasant(name, power), Priest::Priest(name, power), Knight::Knight(name, power)
{
    std::cout << _Name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << _Name << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return (Knight::attack());
}

int Paladin::special()
{
    return (Enchanter::special());
}

void Paladin::rest()
{
    return (Priest::rest());
}

