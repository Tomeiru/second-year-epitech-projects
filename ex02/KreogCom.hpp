/*
** EPITECH PROJECT, 2022
** PM
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

#include <iostream>

class KreogCom {
    public:
        KreogCom(int x, int y, int serial, KreogCom *);
        KreogCom(int x, int y, int serial);
        ~KreogCom();
        void addCom(int x, int y, int serial);
        KreogCom *createNewCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom() const;
        void ping() const;
        void locateSquad() const;
    private:
        const int m_serial;
        int m_x;
        int m_y;
        bool first;
        KreogCom *next;
};

#endif /* !KREOGCOM_HPP_ */
