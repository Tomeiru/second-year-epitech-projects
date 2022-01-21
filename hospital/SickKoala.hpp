/*
** EPITECH PROJECT, 2022
** Day6
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <iostream>

class SickKoala {
    public:
        SickKoala(std::string);
        ~SickKoala();
        void poke();
        bool takeDrug(std::string);
        void overDrive(std::string);
        std::string getName();
    private:
        std::string name;
};

#endif /* !SICKKOALA_HPP_ */