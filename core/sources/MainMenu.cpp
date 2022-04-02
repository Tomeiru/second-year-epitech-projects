/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** MainMenu
*/

#include "MainMenu.hpp"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::init(ICore *coreHandle)
{
    _core = coreHandle;
    _core->setPixelsPerCell(8);
    _core->setFramerate(30);
    _core->openWindow((IDisplayModule::Vector2u){50, 50});
    _text = _core->loadTexture("assets/font/Joystix.TTF", 'h', ICore::Color::yellow, ICore::Color::red, 8, 8);
    _pac = _core->loadTexture("assets/pac.png", ' ', ICore::Color::yellow, ICore::Color::black, 13, 13);
}

void MainMenu::checkPressedButton()
{
}

void MainMenu::update()
{
    checkPressedButton();
    return;
}

void MainMenu::draw()
{
    ICore::Sprite sprite;
    ICore::Sprite spritePac;

    sprite.pixelPosition = {8, 8};
    spritePac.pixelPosition = {16, 16};
    sprite.texture = _text;
    spritePac.texture =_pac;

    _core->clearScreen(ICore::Color::black);
    _core->renderSprite(sprite);
    _core->renderSprite(spritePac);
    return;
}