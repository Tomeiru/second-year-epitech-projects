/*
** EPITECH PROJECT, 2022
** Day10
** File description:
** Lemon
*/

#ifndef LEMON_HPP_
#define LEMON_HPP_

#include "Fruit.hpp"

class Lemon : public Fruit {
    public:
        Lemon();
        ~Lemon();
        std::string getName() const;
        int getVitamins() const;
    protected:
        std::string _name;
        int _vitamins;
    private:
};

#endif /* !LEMON_HPP_ */
