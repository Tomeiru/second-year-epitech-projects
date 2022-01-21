/*
** EPITECH PROJECT, 2022
** Day6
** File description:
** SickKoalaList
*/

#ifndef SICKKOALALIST_HPP_
#define SICKKOALALIST_HPP_

#include "SickKoala.hpp"

class SickKoalaList {
    public:
        SickKoalaList(SickKoala *);
        ~SickKoalaList();
        bool isEnd();
        void append(SickKoalaList *);
        SickKoala *getFromName(std::string);
        SickKoalaList *remove(SickKoalaList *);
        SickKoalaList *removeFromName(std::string);
        SickKoala *getContent();
        SickKoalaList *getNext();
        void dump();
    private:
        SickKoala *patient;
        SickKoalaList *next;
        SickKoalaList *prev;
};

#endif /* !SICKKOALALIST_HPP_ */
