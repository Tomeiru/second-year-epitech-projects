/*
** EPITECH PROJECT, 2022
** Day7
** File description:
** Parts
*/

#include "Parts.hpp"

Arms::Arms(std::string serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

Arms::Arms(std::string serial)
{
    _serial = serial;
    _functional = true;
}

Arms::Arms(bool functional)
{
    _serial = "A-01";
    _functional = functional;
}

Arms::Arms()
{
    _serial = "A-01";
    _functional = true;
}

Arms::~Arms()
{
}

bool Arms::isFunctional(void) const
{
    return (_functional);
}

std::string Arms::serial(void) const
{
    return (_serial);
}

void Arms::informations(void) const
{
    std::cout << "    [Parts] Arms " << _serial << " status: " << (_functional == true ? "OK" : "KO") << std::endl;
}

Legs::Legs(std::string serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

Legs::Legs(std::string serial)
{
    _serial = serial;
    _functional = true;
}

Legs::Legs(bool functional)
{
    _serial = "L-01";
    _functional = functional;
}

Legs::Legs()
{
    _serial = "L-01";
    _functional = true;
}

Legs::~Legs()
{
}

bool Legs::isFunctional(void) const
{
    return (_functional);
}

std::string Legs::serial(void) const
{
    return (_serial);
}

void Legs::informations(void) const
{
    std::cout << "    [Parts] Legs " << _serial << " status: " << (_functional == true ? "OK" : "KO") << std::endl;
}

Head::Head(std::string serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

Head::Head(std::string serial)
{
    _serial = serial;
    _functional = true;
}

Head::Head(bool functional)
{
    _serial = "H-01";
    _functional = functional;
}

Head::Head()
{
    _serial = "H-01";
    _functional = true;
}

Head::~Head()
{
}

bool Head::isFunctional(void) const
{
    return (_functional);
}

std::string Head::serial(void) const
{
    return (_serial);
}

void Head::informations(void) const
{
    std::cout << "    [Parts] Head " << _serial << " status: " << (_functional == true ? "OK" : "KO") << std::endl;
}