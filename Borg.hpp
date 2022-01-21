/*
** EPITECH PROJECT, 2022
** AM
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#include <iostream>
#include "WarpSystem.hpp"

namespace Borg
{
    class Ship {
        public:
            Ship();
            ~Ship();
            void setupCore(WarpSystem::Core *);
            void checkCore();
            bool move(int, Destination);
            bool move(int);
            bool move(Destination);
            bool move();
        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;
    };
}

#endif /* !BORG_HPP_ */
