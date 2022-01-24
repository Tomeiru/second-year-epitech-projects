/*
** EPITECH PROJECT, 2022
** Day9
** File description:
** Knight
*/

#ifndef KNIGHT_HPP_
#define KNIGHT_HPP_

#include "Peasant.hpp"

class Knight : public Peasant {
    public:
        Knight(const std::string &, int);
        ~Knight();
        int attack();
        int special();
        void rest();
    protected:
    private:
};

#endif /* !KNIGHT_HPP_ */
