/*
** EPITECH PROJECT, 2022
** Day10
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <iostream>

class Fruit {
    public:
        ~Fruit();
        std::string getName() const;
        int getVitamins() const;

    protected:
        std::string _name;
        int _vitamins;
    private:
};

#endif /* !FRUIT_HPP_ */
