/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArcadeNcurses
*/

#include "ArcadeNcurses.hpp"

ArcadeNcurses::ArcadeNcurses()
{
    _pixelsPerCell = 0;
    std::cout << "I constructed the ArcadeNcurses struct" << std::endl;
}

ArcadeNcurses::~ArcadeNcurses()
{
    endwin();
    std::cout << "I deconstructed the ArcadeNcurses struct" << std::endl;
}

std::unique_ptr<IDisplayModule> gEpitechArcadeGetDisplayModuleHandle(void)
{
    return (std::make_unique<ArcadeNcurses>());
}

void ArcadeNcurses::setPixelsPerCell(std::uint32_t pixelsPerCell)
{
    UNUSED(pixelsPerCell);
    std::cout << "kekw" << std::endl;
    return;
}

std::uint32_t ArcadeNcurses::getPixelsPerCell(void)
{
    return (_pixelsPerCell);
}

std::unique_ptr<IDisplayModule::RawTexture> ArcadeNcurses::loadTexture(const std::string &pngFilename, char character, IDisplayModule::Color characterColor, IDisplayModule::Color backgroundColor, std::size_t width, std::size_t height)
{
    UNUSED(pngFilename);
    UNUSED(character);
    UNUSED(characterColor);
    UNUSED(backgroundColor);
    UNUSED(width);
    UNUSED(height);
    return (nullptr);
}

void ArcadeNcurses::openWindow(IDisplayModule::Vector2u windowSize)
{
    initscr();
    WINDOW *win = !windowSize.y && !windowSize.x ?
    newwin(LINES, COLS, 0, 0) :
    newwin(windowSize.y, windowSize.x, (LINES - windowSize.y) / 2, (COLS - windowSize.x) / 2);
    box(win, 0, 0);
    refresh();
    wrefresh(win);
    setWindow(win);
    return;
}

bool ArcadeNcurses::isButtonPressed(IDisplayModule::Button button)
{
    UNUSED(button);
    return (true);
}

IDisplayModule::MouseButtonReleaseEvent ArcadeNcurses::getMouseButtonReleaseEvent()
{
    MouseButtonReleaseEvent *ptr = new MouseButtonReleaseEvent;
    return (*ptr);
}

void ArcadeNcurses::startTextInput()
{
    return;
}

std::string ArcadeNcurses::getTextInput()
{
    return (std::string("Lol"));
}

void ArcadeNcurses::endTextInput()
{
    return;
}

void ArcadeNcurses::clearScreen(IDisplayModule::Color color)
{
    UNUSED(color);
    return;
}

void ArcadeNcurses::renderSprite(IDisplayModule::Sprite sprite)
{
    UNUSED(sprite);
    return;
}

void ArcadeNcurses::display()
{
    return;
}

WINDOW *ArcadeNcurses::getWindow()
{
    return (_win);
}

void ArcadeNcurses::setWindow(WINDOW *win)
{
    _win = win;
}
