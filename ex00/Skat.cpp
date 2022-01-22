/*
** EPITECH PROJECT, 2022
** Day7
** File description:
** Skat
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks)
{
    _name = name;
    _stimPaks = stimPaks;
}

Skat::Skat(const std::string &name)
{
    _name = name;
    _stimPaks = 15;
}

Skat::Skat(int stimPaks)
{
    _name = "bob";
    _stimPaks = stimPaks;
}

Skat::Skat()
{
    _name = "bob";
    _stimPaks = 15;
}

Skat::~Skat()
{
}

int &Skat::stimPaks(void)
{
    return (_stimPaks);
}

const std::string &Skat::name(void)
{
    return (_name);
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number > _stimPaks) {
        std::cout << "Don't be greedy" << std::endl;
        return;
    }
    stock += number;
    _stimPaks -= number;
    std::cout << "Keep the change." << std::endl;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
    _stimPaks += number;
}

void Skat::useStimPaks(void)
{
    if (_stimPaks <= 0) {
        std::cout << "Mediiiiiic" << std::endl;
        return;
    }
    std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    _stimPaks -= 1;
}

void Skat::status(void) const
{
    std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir!" << std::endl;
}
