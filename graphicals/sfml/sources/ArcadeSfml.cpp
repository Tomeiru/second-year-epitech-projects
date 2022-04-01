/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArcadeSfml
*/

#include "RawTextureSfml.hpp"

ArcadeSfml::ArcadeSfml()
{
    _pixelsPerCell = 0;
    _isTextInputOn = false;
    _isClosing = false;
    _textInput = "";
    std::cerr << "SFML: I constructed the ArcadeSfml class" << std::endl;
}

ArcadeSfml::~ArcadeSfml()
{
    _win.close();
    std::cerr << "SFML: I deconstructed the ArcadeSfml class" << std::endl;
}

std::unique_ptr<IDisplayModule> gEpitechArcadeGetDisplayModuleHandle(void) //DONE
{
    std::cerr << "SFML: I'm creating the ArcadeSfml class" << std::endl;
    return (std::make_unique<ArcadeSfml>());
}

void ArcadeSfml::setPixelsPerCell(std::uint32_t pixelsPerCell) //DONE
{
    _pixelsPerCell = pixelsPerCell;
    std::cerr << "SFML: I've set PixelsPerCell" << std::endl;
}

std::uint32_t ArcadeSfml::getPixelsPerCell(void) //DONE
{
    std::cerr << "SFML: I'm getting PixelsPerCell" << std::endl;
    return (_pixelsPerCell);
}

std::unique_ptr<IDisplayModule::RawTexture> ArcadeSfml::loadTexture(const std::string &pngFilename, char character, IDisplayModule::Color characterColor, IDisplayModule::Color backgroundColor, std::size_t width, std::size_t height) //DONE
{
    std::cerr << "SFML: I've loaded a texture in Ncurses" << std::endl;
    UNUSED(width);
    UNUSED(height);
    return (std::make_unique<RawTextureSfml>(pngFilename, character, characterColor, backgroundColor, _pixelsPerCell));
}

void ArcadeSfml::openWindow(IDisplayModule::Vector2u windowSize)//DONE
{
    _win.create(sf::VideoMode(windowSize.x, windowSize.y), "Arcade");
    std::cerr << "SFML: I opened a window" << std::endl;
    return;
}

bool ArcadeSfml::isButtonPressed(IDisplayModule::Button button)//DONE IN THEORY
{
    std::cerr << "SFML: I'm in isButtonPressed for " << keyToSfmlKey.at(button) << std::endl;
    if (sf::Keyboard::isKeyPressed(keyToSfmlKey.at(button)))
        return (true);
    return (false);
}

IDisplayModule::MouseButtonReleaseEvent ArcadeSfml::getMouseButtonReleaseEvent() //DONE IN THEORY (test needed)
{
    std::cerr << "SFML: I'm in getMouseButtonReleaseEvent" << std::endl;
    MouseButtonReleaseEvent event;

    event.type = MouseButtonReleaseEvent::Type::None;
    event.cellPosition = (IDisplayModule::Vector2u){0, 0};

    for (size_t i = 0; i < _evtQueue.size(); i++) {
        if (_evtQueue[i].mouseButton.button != sf::Mouse::Right && _evtQueue[i].mouseButton.button != sf::Mouse::Left)
            continue;
        event.type = _evtQueue[i].mouseButton.button == sf::Mouse::Right ? MouseButtonReleaseEvent::Type::Right : MouseButtonReleaseEvent::Type::Left;
        event.cellPosition.x = _evtQueue[i].mouseButton.x / _pixelsPerCell;
        event.cellPosition.y = _evtQueue[i].mouseButton.y / _pixelsPerCell;
    }
    return (event);
}

void ArcadeSfml::startTextInput() //DONE
{
    std::cerr << "SFML: I'm starting text input" << std::endl;
    _isTextInputOn = true;
    return;
}

std::string ArcadeSfml::getTextInput() //DONE
{
    std::cerr << "SFML: I'm in the middle of getting text input" << std::endl;
    return (_textInput);
}

void ArcadeSfml::endTextInput() //DONE
{
    std::cerr << "SFML: I'm finishing text input" << std::endl;
    _isTextInputOn = false;
    _textInput = "";
    return;
}

//First is background then foreground
void ArcadeSfml::clearScreen(IDisplayModule::Color color) //DONE
{
    _win.clear(colorToSfmlColor.at(color));
    std::cerr << "SFML: I have cleared the screen" << std::endl;
    return;
}

void ArcadeSfml::renderSprite(IDisplayModule::Sprite sprite) //DONE
{
    RawTextureSfml *rawTexture = dynamic_cast<RawTextureSfml *>(sprite.texture);
    sf::Texture texture = rawTexture->getTexture();
    sf::Sprite sfmlSprite(texture);
    sfmlSprite.setPosition(sf::Vector2f((float)sprite.rawPixelPosition.x, (float)sprite.rawPixelPosition.y));
    std::cerr << "SFML: I will render sprite" << std::endl;
    return;
}

void ArcadeSfml::display() //DONE
{
    _win.display();
    std::cerr << "SFML: I displayed (refreshed) the window" << std::endl;
    return;
}

bool ArcadeSfml::isClosing() //DONE
{
    std::cerr << "SFML: I'm determining if i'm closing" << std::endl;
    return (_isClosing);
}

void ArcadeSfml::update(void) //DONE
{
    sf::Event event;
    std::cerr << "SFML: I'm gonna update" << std::endl;

    while (_win.pollEvent(event)) {
        if (event.type == sf::Event::Resized)
            _win.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
        else if (event.type == sf::Event::KeyPressed) {
            if (_isTextInputOn && (event.key.code >= 0 && event.key.code <= 35)) {
                if (event.key.code > 25)
                    _textInput.push_back((char) event.key.code + 22);
                else
                    _textInput.push_back((char) event.key.code + 97);
            }
        }else if (event.type == sf::Event::Closed)
            _isClosing = true;
        else if (event.type == sf::Event::MouseButtonReleased)
            _evtQueue.push_back(event);
    }
    return;
}