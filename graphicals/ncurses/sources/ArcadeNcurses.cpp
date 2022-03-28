/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArcadeNcurses
*/

#include "RawTextureNcurses.hpp"

ArcadeNcurses::ArcadeNcurses()
{
    _pixelsPerCell = 0;
    _win = NULL;
    _input = -1;
    std::cerr << "I constructed the ArcadeNcurses class" << std::endl;
}

ArcadeNcurses::~ArcadeNcurses()
{
    endwin();
    std::cerr << "I deconstructed the ArcadeNcurses class" << std::endl;
}

std::unique_ptr<IDisplayModule> gEpitechArcadeGetDisplayModuleHandle(void) //DONE
{
    std::cerr << "I'm creating the ArcadeNcurses class" << std::endl;
    return (std::make_unique<ArcadeNcurses>());
}

void ArcadeNcurses::setPixelsPerCell(std::uint32_t pixelsPerCell) //DONE
{
    _pixelsPerCell = pixelsPerCell;
    std::cerr << "I've set PixelsPerCell" << std::endl;
}

std::uint32_t ArcadeNcurses::getPixelsPerCell(void) //DONE
{
    std::cerr << "I'm getting PixelsPerCell" << std::endl;
    return (_pixelsPerCell);
}

std::unique_ptr<IDisplayModule::RawTexture> ArcadeNcurses::loadTexture(const std::string &pngFilename, char character, IDisplayModule::Color characterColor, IDisplayModule::Color backgroundColor, std::size_t width, std::size_t height) //DONE
{
    std::cerr << "I've loaded a texture in Ncurses" << std::endl;
    UNUSED(pngFilename);
    return (std::make_unique<RawTextureNcurses>(character, characterColor, backgroundColor, width, height));
}

void ArcadeNcurses::openWindow(IDisplayModule::Vector2u windowSize)//DONE IN THEORY (test needed)
{
    initscr();
    nodelay(stdscr, TRUE);
    WINDOW *win = !windowSize.y && !windowSize.x ?
    newwin(LINES, COLS, 0, 0) :
    newwin(windowSize.y, windowSize.x, (LINES - windowSize.y) / 2, (COLS - windowSize.x) / 2);
    nodelay(win, TRUE);
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    start_color();
    initAllColorPair();
    mousemask(BUTTON1_RELEASED | BUTTON2_RELEASED, NULL);
    box(win, 0, 0);
    refresh();
    wrefresh(win);
    setWindow(win);
    std::cerr << "I opened a window" << std::endl;
    return;
}

bool ArcadeNcurses::isButtonPressed(IDisplayModule::Button button)//DONE IN THEORY (test needed)
{
    std::cerr << "I'm in isButtonPressed for " << keyToCursesKey.at(button) << std::endl;
    if (_input == keyToCursesKey.at(button))
        return (true);
    return (false);
}

IDisplayModule::MouseButtonReleaseEvent ArcadeNcurses::getMouseButtonReleaseEvent() //DONE IN THEORY (test needed)
{
    std::cerr << "I'm in getMouseButtonReleaseEvent" << std::endl;
    MouseButtonReleaseEvent event;
    MEVENT eventNcurses;

    event.type = MouseButtonReleaseEvent::Type::None;
    event.cellPosition = (IDisplayModule::Vector2u){0, 0};
    if (_input == KEY_MOUSE)
        if (!getmouse(&eventNcurses)) {
            if (eventNcurses.bstate & BUTTON1_RELEASED)
                event.type = MouseButtonReleaseEvent::Type::Left;
            if (eventNcurses.bstate & BUTTON2_RELEASED)
                event.type = MouseButtonReleaseEvent::Type::Right;
            event.cellPosition = (IDisplayModule::Vector2u){(uint32_t)eventNcurses.x, (uint32_t)eventNcurses.y};
        }
    return (event);
}

void ArcadeNcurses::startTextInput()
{
    std::cerr << "I'm starting text input" << std::endl;
    return;
}

std::string ArcadeNcurses::getTextInput()
{
    std::cerr << "I'm in the middle of getting text input" << std::endl;
    return (std::string("Lol"));
}

void ArcadeNcurses::endTextInput()
{
    std::cerr << "I'm finishing text input" << std::endl;
    return;
}

void ArcadeNcurses::clearScreen(IDisplayModule::Color color) //DONE
{
    //wbkgd(_win, COLOR_PAIR((int)color + 1));
    wbkgd(_win, COLOR_PAIR((int)color * 8 + (int) color + 1));
    std::cerr << "I have cleared the screen" << std::endl;
    return;
}

void ArcadeNcurses::renderSprite(IDisplayModule::Sprite sprite) //DONE
{
    RawTextureNcurses *texture = dynamic_cast<RawTextureNcurses *>(sprite.texture);
    char character = texture->getCharacter();

    attron(COLOR_PAIR(texture->getColor()));
    for (std::size_t i = 0; i < texture->getHeight(); i++) {
        for (std::size_t ii = 0; ii < texture->getWidth(); ii++)
            mvwprintw(_win, sprite.rawPixelPosition.y + i, sprite.rawPixelPosition.x + ii, "%c", character);
    }
    attroff(COLOR_PAIR(texture->getColor()));
    return;
}

void ArcadeNcurses::display() //DONE
{
    wrefresh(_win);
    std::cerr << "I displayed (refreshed) the window" << std::endl;
    return;
}

bool ArcadeNcurses::isClosing()
{
    std::cerr << "I'm determining if i'm closing" << std::endl;
    return (false);
}

void ArcadeNcurses::update(void) //DONE
{
    std::cerr << "I'm gonna update" << std::endl;
    werase(_win);
    box(_win, 0, 0);
    _input = getch();
    return;
}

WINDOW *ArcadeNcurses::getWindow() //DONE
{
    std::cerr << "I'm getting the window" << std::endl;
    return (_win);
}

void ArcadeNcurses::setWindow(WINDOW *win) //DONE
{
    std::cerr << "I'm setting the window" << std::endl;
    _win = win;
}

void ArcadeNcurses::initAllColorPair(void) //DONE
{
    std::cerr << "I'm initializing all the color pair for ncurses" << std::endl;
    int i = 1;

    for (int ii = 0; ii < 8; ii++)
        for (int iii = 0; iii < 8; iii++)
                init_pair(i++, iii, ii);
}