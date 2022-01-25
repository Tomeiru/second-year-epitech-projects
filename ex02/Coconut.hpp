/*
** EPITECH PROJECT, 2022
** Day10B
** File description:
** Coconut
*/

#ifndef COCONUT_HPP_
#define COCONUT_HPP_

class Fruit;

#include "Fruit.hpp"

class Coconut : public Fruit {
    public:
        Coconut();
        ~Coconut();
        std::string getName() const;
        int getVitamins() const;
    protected:
        std::string _name;
        int _vitamins;
    private:
};

#endif /* !COCONUT_HPP_ */
