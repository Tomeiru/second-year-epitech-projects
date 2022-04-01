/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Texture
*/

#include "Texture.hpp"

ICore::Texture::Texture(const std::string &pngFilename, char character, ICore::Color characterColor, ICore::Color backgroundColor, std::size_t width, std::size_t height, std::unique_ptr<IDisplayModule::RawTexture> texture)
{
    _pngFilename = pngFilename;
    _character = character;
    _characterColor = characterColor;
    _backgroundColor = backgroundColor;
    _width = width;
    _height = height;
    _texture = std::move(texture);
}

ICore::Texture::~Texture()
{
}

IDisplayModule::RawTexture *ICore::Texture::getTexture(void)
{
    return (_texture.get());
}

