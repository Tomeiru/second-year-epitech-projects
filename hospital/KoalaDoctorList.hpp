/*
** EPITECH PROJECT, 2022
** Day6
** File description:
** KoalaDoctorList
*/

#ifndef KOALADOCTORLIST_HPP_
#define KOALADOCTORLIST_HPP_

#include "KoalaDoctor.hpp"

class KoalaDoctorList {
    public:
        KoalaDoctorList(KoalaDoctor *);
        ~KoalaDoctorList();
        bool isEnd();
        void append(KoalaDoctorList *);
        KoalaDoctor *getFromName(std::string);
        KoalaDoctorList *remove(KoalaDoctorList *);
        KoalaDoctorList *removeFromName(std::string);
        void dump();
    private:
        KoalaDoctor *patient;
        KoalaDoctorList *next;
        KoalaDoctorList *prev;
};

#endif /* !KOALADOCTORLIST_HPP_ */
