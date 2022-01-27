/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture(const std::string &file)
{
    std::ifstream content(file);
    std::stringstream contentStream;

    if (content.is_open()) {
        contentStream << content.rdbuf();
        _data = contentStream.str();
        return;
    }
    _data = "ERROR";
}

Picture::Picture(const Picture &other)
{
    _data = other._data;
}

Picture::Picture()
{
    _data = "";
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream content(file);
    std::stringstream contentStream;

    if (content.is_open()) {
        contentStream << content.rdbuf();
        _data = contentStream.str();
        return (true);
    }
    _data = "ERROR";
    return (false);
}

void Picture::operator=(const Picture &other)
{
    _data = other._data;
}

void Picture::operator=(const std::string &other)
{
    _data = other;
}

