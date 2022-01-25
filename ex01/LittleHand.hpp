/*
** EPITECH PROJECT, 2022
** Day10B
** File description:
** LittleHand
*/

#ifndef LITTLEHAND_HPP_
#define LITTLEHAND_HPP_

class FruitBox;

#include "FruitBox.hpp"

class LittleHand {
    public:
        LittleHand();
        ~LittleHand();
        static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
};

#endif /* !LITTLEHAND_HPP_ */
