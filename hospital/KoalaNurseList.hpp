/*
** EPITECH PROJECT, 2022
** Day6
** File description:
** KoalaNurseList
*/

#ifndef KOALANURSELIST_HPP_
#define KOALANURSELIST_HPP_

#include "KoalaNurse.hpp"

class KoalaNurseList {
    public:
        KoalaNurseList(KoalaNurse *);
        ~KoalaNurseList();
        bool isEnd();
        void append(KoalaNurseList *);
        KoalaNurse *getFromID(int id);
        KoalaNurseList *remove(KoalaNurseList *);
        KoalaNurseList *removeFromID(int id);
        void dump();
    private:
        KoalaNurse *patient;
        KoalaNurseList *next;
        KoalaNurseList *prev;
};

#endif /* !KOALANURSELIST_HPP_ */
