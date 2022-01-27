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
    Error err;
    _error = err;
}

Toy::Toy(const Toy &other)
{
    _type = other._type;
    _name = other._name;
    _ascii = other._ascii;
    _error = _error;
}

Toy::Toy()
{
    _type = BASIC_TOY;
    _name = "toy";
    Picture _ascii;
    Error err;
    _error = err;
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
    Error err(Error::PICTURE, "bad new illustration", "setAscii");
    _error = err;
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

std::string Toy::Error::what() const
{
    return (error_msg);
}

std::string const &Toy::Error::where() const
{
    return (where_str);
}

const Toy &Toy::operator<<(const std::string &string)
{
    _ascii = string;
    return (*this);
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

Toy::Error::~Error()
{
}

void Toy::Error::operator=(const Toy::Error &other)
{
    type = other.type;
    error_msg = other.error_msg;
    where_str = other.where_str;
}
