/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** MainMenu
*/

#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#include "IGameModule.hpp"

class Arcade;

class MainMenu {
    public:
        MainMenu();
        ~MainMenu();
        void init(Arcade *coreHandle);
        void update();
        void draw();
        void checkPressedButton();
    protected:
        Arcade *_core;
        ICore::Texture *_text;
        ICore::Texture *_pac;
    private:
};

#endif /* !MAINMENU_HPP_ */
