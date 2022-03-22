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

    protected:
        void *_dlGraphical;
        std::unique_ptr<IDisplayModule> _graphical;
        void *_dlGame;
        std::unique_ptr<IGameModule> _game;
    private:
};

#endif /* !ARCADE_HPP_ */
