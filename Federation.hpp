/*
** EPITECH PROJECT, 2022
** AM
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#pragma once

#include <iostream>

namespace Federation {
    namespace Starfleet {
        class Captain;
        class Ship;
        class Ensign;
    }
}

namespace Borg {
    class Ship;
}

#include "WarpSystem.hpp"
#include "Borg.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Captain {
            public:
                Captain(std::string);
                ~Captain();
                std::string getName();
                int getAge();
                void setAge(int age);
            private:
                std::string _name;
                int _age;
        };
        class Ship {
            public:
                Ship();
                Ship(int, int , std::string, short);
                Ship(int, int, std::string, short, int);
                ~Ship();
                void setupCore(WarpSystem::Core *);
                void checkCore();
                void promote(Captain *);
                bool move(int, Destination);
                bool move(int);
                bool move(Destination);
                bool move();
                int getShield();
                void setShield(int shield);
                int getTorpedo();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *);
                void fire(int, Borg::Ship *);
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core;
                Captain *_captain;
                Destination _location;
                Destination _home;
                int _shield;
                int _photonTorpedo;
        };
        class Ensign {
            public:
                Ensign(std::string);
                ~Ensign();
            private:
                std::string _name;
        };
    }
    class Ship {
        public:
            Ship(int, int, std::string);
            ~Ship();
            void setupCore(WarpSystem::Core*);
            void checkCore();
            bool move(int, Destination);
            bool move(int);
            bool move(Destination);
            bool move();
            WarpSystem::Core *_core;
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            Destination _location;
            Destination _home;
    };
}

#endif /* !FEDERATION_HPP_ */
