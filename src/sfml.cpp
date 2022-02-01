/*
** EPITECH PROJECT, 2022
** Rush3Clean
** File description:
** sfml
*/

#include "MyGKrellmInfo.hpp"
#include "SFML/Graphics.hpp"
#include <cmath>

void keyGestion(MyGKrellmInfo *info, sf::RenderWindow &window, sf::Event &event)
{
    if (event.key.code == sf::Keyboard::Q)
        window.close();
    if (event.key.code == sf::Keyboard::H)
        info->getHelpModule()->toggleDisplayed();
    if (event.key.code == sf::Keyboard::U)
        info->getHostUsername()->toggleDisplayed();
    if (event.key.code == sf::Keyboard::O)
        info->getOSKernelVersion()->toggleDisplayed();
    if (event.key.code == sf::Keyboard::D)
        info->getDateTime()->toggleDisplayed();
    if (event.key.code == sf::Keyboard::S) {
        window.close();
        startCurses(info);
    }

}

unsigned int getHeight(MyGKrellmInfo *info)
{
    int i = 0;

    for (ModuleList_t *temp = info->getModules(); temp != nullptr; temp = temp->next)
        if (temp->module->getDisplayed() == true)
            i++;
    return (i == 0 ? 1 : i * 300);
}

void startSFML(MyGKrellmInfo *info)
{
    unsigned int height = getHeight(info);
    sf::RenderWindow window(sf::VideoMode(600, height), "MyGKrellm");
    sf::Event event;
    sf::Texture texture;
    if (!texture.loadFromFile("assets/modulebackground.jpg"))
        exit(84);
    sf::Sprite sprite(texture);
    sf::Font font;
    float y = 120;

    font.loadFromFile("assets/font.ttf");
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        sprite.setPosition(0, 0);
        window.draw(sprite);
        sprite.setPosition(0, 300);
        window.draw(sprite);
        sprite.setPosition(0, 600);
        window.draw(sprite);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased)
                keyGestion(info, window, event);
        }
        for (ModuleList_t *temp = info->getModules(); temp != nullptr; temp = temp->next)
            if (info->getHelpModule()->getDisplayed() == true) {
                sf::Text text(info->getHelpModule()->getData(), font, 30);
                window.draw(text);
            }
            else if (temp->module->getDisplayed() == true) {
                sf::Text title(temp->module->getTitle(), font, 30);
                sf::Vector2f center = { std::round(title.getGlobalBounds().width / 2.f),
                std::round(title.getGlobalBounds().height / 2.f)};
                title.setOrigin(center);
                title.setPosition(sf::Vector2f(300, y));
                y += 30;
                sf::Text text(temp->module->getData(), font, 30);
                sf::Vector2f center_sec = { std::round(text.getGlobalBounds().width / 2.f),
                std::round(text.getGlobalBounds().height / 2.f)};
                text.setOrigin(center_sec);
                text.setPosition(sf::Vector2f(300, y));
                y += 270;
                window.draw(title);
                window.draw(text);
            }
        y = 120;
        window.display();
        info->getDateTime()->updateData();
    }
}