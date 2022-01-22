/*
** EPITECH PROJECT, 2022
** AM
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#pragma once

namespace Federation {
    namespace Starfleet {
        class Captain;
        class Ship;
        class Ensign;
    }
    class Ship;
}

namespace Borg {
    class Ship;
}

#include <iostream>
#include "WarpSystem.hpp"
#include "Federation.hpp"

namespace Borg
{
    class Ship {
        public:
            Ship(int, short);
            Ship(int);
            Ship();
            ~Ship();
            void setupCore(WarpSystem::Core *);
            void checkCore();
            bool move(int, Destination);
            bool move(int);
            bool move(Destination);
            bool move();
            int getShield();
            void setShield(int);
            int getWeaponFrequency();
            void setWeaponFrequency(int);
            short getRepair();
            void setRepair(short repair);
            void fire(Federation::Starfleet::Ship *);
            void fire(Federation::Ship *);
            void repair();
        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;
            int _shield;
            int _weaponFrequency;
            short _repair;
    };
}

#endif /* !BORG_HPP_ */
