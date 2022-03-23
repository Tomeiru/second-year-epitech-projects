/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include "ArgumentChecker.hpp"

class Arcade {
    public:
        Arcade();
        ~Arcade();
        void setDlGraphical(void *graphical);
        void changeLibraryByPath(std::string path, bool graphical);
        void initClassFromDl(bool graphical);
        void closeDl(bool graphical);
        std::unique_ptr<IDisplayModule> _graphical;
        std::unique_ptr<IGameModule> _game;
    protected:
        void *_dlGraphical;
        void *_dlGame;
    private:
};

#endif /* !ARCADE_HPP_ */
