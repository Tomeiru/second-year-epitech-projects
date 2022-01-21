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
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core;
                Captain *_captain;
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
        private:
            int _length;
            int _width;
            std::string _name;
            WarpSystem::Core *_core;
    };
}

#endif /* !FEDERATION_HPP_ */
