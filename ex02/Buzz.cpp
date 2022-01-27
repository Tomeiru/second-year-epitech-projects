/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &filename) : Toy(BUZZ, name, filename)
{
}

Buzz::Buzz(const std::string &name) : Toy (BUZZ, name, "buzz.txt")
{
}

Buzz::~Buzz()
{
}
