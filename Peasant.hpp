/*
** EPITECH PROJECT, 2022
** Day9
** File description:
** Peasant
*/

#ifndef PEASANT_HPP_
#define PEASANT_HPP_

#include <iostream>

class Peasant {
    public:
        Peasant(const std::string &, int);
        ~Peasant();
        const std::string &getName() const;
        int getPower() const;
        int getHp() const;
        int attack();
        int special();
        void rest();
        void damage(int damage);
    protected:
        std::string _Name;
        int _Power;
        int _Hp;
};

#endif /* !PEASANT_HPP_ */
