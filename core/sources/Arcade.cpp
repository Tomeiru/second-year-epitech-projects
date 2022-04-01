/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade
*/

#include "Arcade.hpp"
#include "Texture.hpp"

// ICore Functions
Arcade::Arcade()
{
    _graphical = nullptr;
    _game = std::make_unique<MainMenu>();
    _dlGame = NULL;
    _dlGraphical = NULL;
    _prevGraphPath = std::string("");
    _nextGraphPath = std::string("");;
    _prevGamePath = std::string("");;
    _nextGamePath = std::string("");;
    _inGame = false;
    _inMenu = true;
    _framerate = 60;
}

Arcade::~Arcade()
{
}

void Arcade::setPixelsPerCell(std::uint32_t pixelsPerCell)
{
    _graphical->setPixelsPerCell(pixelsPerCell);
}

void Arcade::setFramerate(unsigned framerate)
{
    _framerate = framerate;
}

ICore::Texture *Arcade::loadTexture(const std::string &pngFilename, char character, ICore::Color characterColor, ICore::Color backgroundColor, std::size_t width, std::size_t height)//TODO
{
    ICore::Texture texture(pngFilename, character, characterColor, backgroundColor, width, height, std::move(_graphical->loadTexture(pngFilename, character, characterColor, backgroundColor, width, height)));

    _textureDeque.push_back(std::move(texture));
    return (&_textureDeque.back());
}

void Arcade::openWindow(IDisplayModule::Vector2u pixelsWantedWindowSize)
{
    _graphical->openWindow(pixelsWantedWindowSize);
}

bool Arcade::isButtonPressed(ICore::Button button)
{
    if (_graphical->isButtonPressed(button))
        return (true);
    return (false);
}

ICore::MouseButtonReleaseEvent Arcade::getMouseButtonReleaseEvent()
{
    return (_graphical->getMouseButtonReleaseEvent());
}

void Arcade::startTextInput()
{
    return (_graphical->startTextInput());
}

std::string Arcade::getTextInput()
{
    return (_graphical->getTextInput());
}

void Arcade::endTextInput()
{
    return (_graphical->endTextInput());
}

void Arcade::clearScreen(ICore::Color color)
{
    return (_graphical->clearScreen(color));
}

void Arcade::renderSprite(ICore::Sprite sprite)//TODO
{
    IDisplayModule::Sprite displaySprite;

    displaySprite.rawPixelPosition = sprite.pixelPosition;
    displaySprite.texture = sprite.texture->getTexture();
    _graphical->renderSprite(displaySprite);
    return;
}

// Personal Functions
void Arcade::changeLibraryByPath(std::string path, bool graphical)
{
    if (path == "")
        return;
    if (graphical) {
        closeDl(true);
        _dlGraphical = dlopen(path.c_str(), RTLD_LAZY);
        initClassFromDl(true);
        return;
    }
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
    if (_dlGame != NULL)
        dlclose(_dlGame);
}

void Arcade::exitArcade()
{
    closeDl(true);
    closeDl(false);
    exit(0);
}

void Arcade::gameRestart(void)
{
    if (_inMenu == true)
        return;
}

void Arcade::goBackToMenu(void)
{
    if (_inMenu == true)
        return;
}

void Arcade::checkFunctionButton(void)
{
    if (isButtonPressed(IDisplayModule::Button::F1))
        changeLibraryByPath(_prevGraphPath, true);
    if (isButtonPressed(IDisplayModule::Button::F2))
        changeLibraryByPath(_nextGraphPath, true);
    if (isButtonPressed(IDisplayModule::Button::F3))
        changeLibraryByPath(_prevGamePath, false);
    if (isButtonPressed(IDisplayModule::Button::F4))
        changeLibraryByPath(_nextGamePath, false);
    if (isButtonPressed(IDisplayModule::Button::F5))
        gameRestart();
    if (isButtonPressed(IDisplayModule::Button::F6))
        goBackToMenu();
    if (isButtonPressed(IDisplayModule::Button::F7))
        exitArcade();
}

void Arcade::gameLoop(void)
{
    struct timespec tend;

    while (1) {
        clock_gettime(CLOCK_MONOTONIC, &tend);
        long oneFrameTime = (long long)((1.f/(float)_framerate) * (1000000000.f));
        if (tend.tv_nsec + oneFrameTime <= 999999999)
            tend.tv_nsec += oneFrameTime;
        else {
            tend.tv_sec += 1;
            tend.tv_nsec = oneFrameTime - (999999999 - tend.tv_nsec);
        }
        _graphical->update();
        checkFunctionButton();
        _game->update();
        _game->draw();
        _graphical->display();
        clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &tend, NULL);
    }
}

void Arcade::launchGame(void)
{
    _game->init(this);
    openWindow((IDisplayModule::Vector2u){50, 50});
    setPixelsPerCell(8);
    setFramerate(30);
    gameLoop();
}

void Arcade::addNewScore(std::uint32_t score)
{
    UNUSED(score);
    return;
}