/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &filename) : Toy(WOODY, name, filename)
{
}

Woody::Woody(const std::string &name) : Toy (WOODY, name, "woody.txt")
{
}

Woody::~Woody()
{
}