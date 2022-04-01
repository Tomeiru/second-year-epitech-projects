/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** MainMenu
*/

#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#include "IGameModule.hpp"

class MainMenu : public IGameModule {
    public:
        MainMenu();
        ~MainMenu();
        void init(ICore *coreHandle);
        void update();
        void draw();
        void checkPressedButton();
    protected:
        ICore *_core;
        ICore::Texture *_text;
    private:
};

#endif /* !MAINMENU_HPP_ */
