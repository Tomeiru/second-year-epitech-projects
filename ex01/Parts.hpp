/*
** EPITECH PROJECT, 2022
** Day7
** File description:
** Parts
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <iostream>

class Arms {
    public:
        Arms(std::string serial, bool functional);
        Arms(std::string serial);
        Arms(bool functional);
        Arms();
        ~Arms();
        bool isFunctional();
        std::string serial();
        void informations();
    private:
        std::string _serial;
        bool _functional;
};

class Legs {
    public:
        Legs(std::string serial, bool functional);
        Legs(std::string serial);
        Legs(bool functional);
        Legs();
        ~Legs();
        bool isFunctional();
        std::string serial();
        void informations();
    private:
        std::string _serial;
        bool _functional;
};

class Head {
    public:
        Head(std::string serial, bool functional);
        Head(std::string serial);
        Head(bool functional);
        Head();
        ~Head();
        bool isFunctional();
        std::string serial();
        void informations();
    private:
        std::string _serial;
        bool _functional;
};

#endif /* !PARTS_HPP_ */
