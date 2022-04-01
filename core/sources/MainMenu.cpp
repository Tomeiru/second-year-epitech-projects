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
    _core->openWindow((IDisplayModule::Vector2u){50, 50});
    _core->setPixelsPerCell(8);
    _core->setFramerate(30);
    _text = _core->loadTexture("kekw", 'h', ICore::Color::yellow, ICore::Color::red, 8, 8);
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

    sprite.pixelPosition = {8, 8};
    sprite.texture = _text;

    _core->clearScreen(ICore::Color::black);
    _core->renderSprite(sprite);
    return;
}