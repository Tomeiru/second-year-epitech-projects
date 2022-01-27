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

bool Toy::speak_es(const std::string &statement)
{
    Error err(Error::SPEAK, "wrong mode", "speak_es");
    _error = err;
    return (false);
}

std::ostream &operator<<(std::ostream &os, const Toy &other)
{
    os << other.getName() << std::endl << other.getAscii() << std::endl;
    return (os);
}

void Toy::operator<<(const std::string &string)
{
    _ascii = string;
}

Toy::Error Toy::getLastError() const
{
    return (_error);
}

Toy::Error::Error(const ErrorType &err_type, std::string err_msg, std::string err_where)
{
    type = err_type;
    error_msg = err_msg;
    where_str = err_where;
}

Toy::Error::Error()
{
    type = UNKNOWN;
    error_msg = "";
    where_str = "";
}

void Toy::Error::operator=(const Toy::Error &other)
{
    type = other.type;
    error_msg = other.error_msg;
    where_str = other.where_str;
}
