/*
** EPITECH PROJECT, 2022
** Day7
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include <iostream>
#include "Parts.hpp"

class KoalaBot {
    public:
        KoalaBot(std::string);
        KoalaBot();
        ~KoalaBot();
        void setParts(const Arms &);
        void setParts(const Legs &);
        void setParts(const Head &);
        void swapParts(Arms &);
        void swapParts(Legs &);
        void swapParts(Head &);
        void informations() const;
        bool status() const;
    private:
        std::string _serial;
        Arms _arm;
        Legs _leg;
        Head _head;

};

#endif /* !KOALABOT_HPP_ */
