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

bool Toy::setAscii(const std::string &filename)
{
    std::ifstream content(filename);
    std::stringstream contentStream;

    if (content.is_open()) {
        contentStream << content.rdbuf();
        _ascii._data = contentStream.str();
        return (true);
    }
    _ascii._data = "ERROR";
    return (false);
}

void Toy::setName(const std::string &name)
{
    _name = name;
}

const Toy &Toy::operator=(const Toy &other)
{
    _type = other._type;
    _name = other._name;
    _ascii = other._ascii;
    return (*this);
}

void Toy::speak(const std::string &statement)
{
    std::cout << _name << " \"" << statement << "\"" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Toy &other)
{
    os << other.getName() << std::endl << other.getAscii() << std::endl;
    return (os);
}

const Toy &Toy::operator<<(const std::string &string)
{
    _ascii = string;
    return (*this);
}
