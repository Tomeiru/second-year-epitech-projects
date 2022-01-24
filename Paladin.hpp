/*
** EPITECH PROJECT, 2022
** Day9
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Priest.hpp"
#include  "Knight.hpp"

class Paladin : public Knight, public Priest{
    public:
        Paladin(const std::string &, int);
        ~Paladin();
        int attack();
        int special();
        void rest();

    protected:
    private:
};

#endif /* !PALADIN_HPP_ */
