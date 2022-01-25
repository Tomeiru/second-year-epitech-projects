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
#include "Coconut.hpp"

class LittleHand {
    public:
        LittleHand();
        ~LittleHand();
        static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
        static FruitBox * const *organizeCoconut(Coconut const * const *coconuts);
};

#endif /* !LITTLEHAND_HPP_ */
