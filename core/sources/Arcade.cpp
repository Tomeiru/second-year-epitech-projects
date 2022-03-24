/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade
*/

#include "Arcade.hpp"

// ICore Functions
Arcade::Arcade()
{
    _dlGame = NULL;
    _dlGraphical = NULL;
    _framerate = 60;
}

Arcade::~Arcade()
{
}

void Arcade::setPixelsPerCell(std::uint32_t pixelsPerCell)
{
    UNUSED(pixelsPerCell);
}

void Arcade::setFramerate(unsigned framerate)
{
    _framerate = framerate;
}

ICore::Texture *Arcade::loadTexture(const std::string &pngFilename, char character, ICore::Color characterColor, ICore::Color backgroundColor, std::size_t width, std::size_t height)
{
    UNUSED(pngFilename);
    UNUSED(character);
    UNUSED(characterColor);
    UNUSED(backgroundColor);
    UNUSED(width);
    UNUSED(height);
    return (nullptr);
}

void Arcade::openWindow(IDisplayModule::Vector2u pixelsWantedWindowSize)
{
    _graphical->openWindow(pixelsWantedWindowSize);
}

bool Arcade::isButtonPressed(ICore::Button button)
{
    UNUSED(button);
    return (true);
}

ICore::MouseButtonReleaseEvent Arcade::getMouseButtonReleaseEvent()
{
    MouseButtonReleaseEvent *ptr = new MouseButtonReleaseEvent;
    return (*ptr);
}

void Arcade::startTextInput()
{
    return;
}

std::string Arcade::getTextInput()
{
    return(std::string("Lol"));
}

void Arcade::endTextInput()
{
    return;
}

void Arcade::clearScreen(ICore::Color color)
{
    UNUSED(color);
    return;
}

void Arcade::renderSprite(ICore::Sprite sprite)
{
    UNUSED(sprite);
    return;
}

// Personal Functions
void Arcade::changeLibraryByPath(std::string path, bool graphical)
{
    if (graphical) {
        closeDl(true);
        _dlGraphical = dlopen(path.c_str(), RTLD_LAZY);
        initClassFromDl(true);
        return;
    }
    if (_dlGame != NULL)
        closeDl(false);
    _dlGame = dlopen(path.c_str(), RTLD_LAZY);
    initClassFromDl(false);
}

void Arcade::setDlGraphical(void *dlGraphical)
{
    _dlGraphical = dlGraphical;
}

void Arcade::initClassFromDl(bool graphical)
{
    std::unique_ptr<IDisplayModule> (*displayHandle)(void);
    std::unique_ptr<IGameModule> (*gameHandle)(void);

    if (graphical) {
        *(void **) &displayHandle = dlsym(_dlGraphical, "gEpitechArcadeGetDisplayModuleHandle");
        _graphical = (*displayHandle)();
        return;
    }
    *(void **) &gameHandle = dlsym(_dlGame, "gEpitechArcadeGetGameModuleHandle");
    _game = (*gameHandle)();
}

void Arcade::closeDl(bool graphical)
{
    if (graphical) {
        _graphical = nullptr;
        dlclose(_dlGraphical);
        return;
    }
    _game = nullptr;
    dlclose(_dlGame);
}

void Arcade::mainMenu(void)
{
    MainMenu menu;
    struct timespec tend;

    menu.init(this);
    openWindow((IDisplayModule::Vector2u){0, 0});
    while (1) {
        clock_gettime(CLOCK_MONOTONIC, &tend);
        long oneFrameTime = (long long)((1.f/60.f) * (1000000000.f));
        if (tend.tv_nsec + oneFrameTime <= 999999999)
            tend.tv_nsec += oneFrameTime;
        else {
            tend.tv_sec += 1;
            tend.tv_nsec = oneFrameTime - (999999999 - tend.tv_nsec);
        }
        _graphical->update();
        menu.update();
        menu.draw();
        _graphical->display();
        clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &tend, NULL);
    }
    //getInput
}