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
    _win = NULL;
    _input = -1;
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
    nodelay(stdscr, TRUE);
    WINDOW *win = !windowSize.y && !windowSize.x ?
    newwin(LINES, COLS, 0, 0) :
    newwin(windowSize.y, windowSize.x, (LINES - windowSize.y) / 2, (COLS - windowSize.x) / 2);
    nodelay(win, TRUE);
    noecho();
    curs_set(0);
    box(win, 0, 0);
    refresh();
    wrefresh(win);
    setWindow(win);
    return;
}

bool ArcadeNcurses::isButtonPressed(IDisplayModule::Button button)
{
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
    wrefresh(_win);
    return;
}

bool ArcadeNcurses::isClosing()
{
    return (false);
}

void ArcadeNcurses::update(void)
{
    static int i = 0;
    static int seconds = 0;
    static int first_time = time(NULL);
    int actual_time = time(NULL);

    seconds = actual_time - first_time;
    werase(_win);
    mvwprintw(_win, 0, 1, "%s", "Main Menu");
    mvwprintw(_win, 10, 10, "%i | %i", i++, seconds);
    box(_win, 0, 0);
    _input = getch();
    if (_input == 'q') {
        endwin();
        exit(1);
    }
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
