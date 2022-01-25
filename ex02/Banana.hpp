/*
** EPITECH PROJECT, 2022
** Day10
** File description:
** Banana
*/

#ifndef BANANA_HPP_
#define BANANA_HPP_

#include "Fruit.hpp"

class Banana : public Fruit {
    public:
        Banana();
        ~Banana();
        std::string getName() const;
        int getVitamins() const;
    protected:
        std::string _name;
        int _vitamins;
    private:
};

#endif /* !BANANA_HPP_ */
