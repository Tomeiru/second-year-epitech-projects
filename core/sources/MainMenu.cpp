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
    _core->loadTexture("kekw", 'h', ICore::Color::yellow, ICore::Color::red, 8, 8);
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
    _core->clearScreen(ICore::Color::black);
    return;
}