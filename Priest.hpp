/*
** EPITECH PROJECT, 2022
** Day9
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Enchanter.hpp"

class Priest : public Enchanter {
    public:
        Priest(const std::string &, int);
        ~Priest();
        void rest();
    protected:
    private:
};

#endif /* !PRIEST_HPP_ */
