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
        virtual ~Fruit();
        virtual std::string getName() const = 0;
        virtual int getVitamins() const = 0;
    protected:
    private:
};

#endif /* !FRUIT_HPP_ */
