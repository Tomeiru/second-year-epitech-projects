/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** CoreTexture
*/

#ifndef CORETEXTURE_HPP_
#define CORETEXTURE_HPP_

#include "ICore.hpp"

class ICore::Texture {
    public:
        Texture(const std::string &pngFilename, char character, ICore::Color characterColor, ICore::Color backgroundColor, std::size_t width, std::size_t height, std::unique_ptr<IDisplayModule::RawTexture> texture);
        Texture(Texture&&) = default;
        ~Texture();
        IDisplayModule::RawTexture *getTexture(void);

    protected:
        std::string _pngFilename;
        char _character;
        ICore::Color _characterColor;
        ICore::Color _backgroundColor;
        std::size_t _width;
        std::size_t _height;
        std::unique_ptr<IDisplayModule::RawTexture> _texture;
    private:
};

#endif /* !CORETEXTURE_HPP_ */
