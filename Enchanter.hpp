/*
** EPITECH PROJECT, 2022
** Day9
** File description:
** Enchanter
*/

#ifndef ENCHANTER_HPP_
#define ENCHANTER_HPP_

#include "Peasant.hpp"

class Enchanter : public Peasant {
    public:
        Enchanter(const std::string &, int);
        ~Enchanter();
        int attack();
        int special();
        void rest();
    protected:
    private:
};

#endif /* !ENCHANTER_HPP_ */
