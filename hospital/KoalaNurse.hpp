/*
** EPITECH PROJECT, 2022
** Day6
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include "SickKoala.hpp"

class KoalaNurse {
    public:
        KoalaNurse(int);
        ~KoalaNurse();
        void giveDrug(std::string, SickKoala*);
        std::string readReport(std::string);
        void timeCheck();
    protected:
        int id;
        bool working;
    private:
};

#endif /* !KOALANURSE_HPP_ */
