/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(const ToyType &type, const std::string &name, const std::string &filename)
{
    _type = type;
    _name = name;
    _ascii = Picture(filename);
}

Toy::Toy(const Toy &other)
{
    _type = other._type;
    _name = other._name;
    _ascii = other._ascii;
}

Toy::Toy()
{
    _type = BASIC_TOY;
    _name = "toy";
    Picture _ascii;
}

Toy::~Toy()
{
}

Toy::ToyType Toy::getType() const
{
    return (_type);
}

std::string Toy::getName() const
{
    return (_name);
}

std::string Toy::getAscii() const
{
    return (_ascii._data);
}

void Toy::setAscii(const std::string &filename)
{
    _ascii = Picture(filename);
}

void Toy::setName(const std::string &name)
{
    _name = name;
}

void Toy::operator=(const Toy &other)
{
    _type = other._type;
    _name = other._name;
    _ascii = other._ascii;
}

void Toy::speak(const std::string &statement)
{
    std::cout << _name << " \"" << statement << "\"" << std::endl;
}
