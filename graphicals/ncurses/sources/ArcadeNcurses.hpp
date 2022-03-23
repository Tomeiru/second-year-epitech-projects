/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArcadeNcurses
*/

#ifndef ARCADENCURSES_HPP_
#define ARCADENCURSES_HPP_

#include "ICore.hpp"
#include <iostream>
#include <vector>

class ArcadeNcurses : public IDisplayModule {
    public:
        ArcadeNcurses();
        ~ArcadeNcurses();
        void setPixelsPerCell(std::uint32_t pixelsPerCell);
        std::uint32_t getPixelsPerCell(void);
        std::unique_ptr<IDisplayModule::RawTexture> loadTexture(const std::string &pngFilename, char character, IDisplayModule::Color characterColor, IDisplayModule::Color backgroundColor, std::size_t width, std::size_t height);
        void openWindow(IDisplayModule::Vector2u pixelsWantedWindowSize);
        bool isButtonPressed(IDisplayModule::Button button);
        IDisplayModule::MouseButtonReleaseEvent getMouseButtonReleaseEvent();
        void startTextInput();
        std::string getTextInput();
        void endTextInput();
        void renderSprite(IDisplayModule::Sprite sprite);
        void display();

    protected:
        std::uint32_t _pixelsPerCell;
    private:
};

#endif /* !ARCADENCURSES_HPP_ */
