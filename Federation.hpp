/*
** EPITECH PROJECT, 2022
** AM
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <iostream>
#include "WarpSystem.hpp"

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
                Ship(int, int , std::string, short);
                ~Ship();
                void setupCore(WarpSystem::Core *);
                void checkCore();
                void promote(Captain *);
                bool move(int, Destination);
                bool move(int);
                bool move(Destination);
                bool move();
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core;
                Captain *_captain;
                Destination _location;
                Destination _home;
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
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;
    };
}

#endif /* !FEDERATION_HPP_ */
