/*
** EPITECH PROJECT, 2022
** Day6
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include <iostream>
#include <fstream>
#include "SickKoala.hpp"

class KoalaDoctor {
    public:
        KoalaDoctor(std::string);
        ~KoalaDoctor();
        void diagnose(SickKoala*);
        void timeCheck();
        std::string getName();
    private:
        std::string doc_name;
        bool working;
};

#endif /* !KOALADOCTOR_HPP_ */
