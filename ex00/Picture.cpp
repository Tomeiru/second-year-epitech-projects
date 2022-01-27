/*
** EPITECH PROJECT, 2022
** Day11
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture(std::string &file)
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
