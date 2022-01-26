/*
** EPITECH PROJECT, 2022
** Day10B
** File description:
** LittleHand
*/

#include "LittleHand.hpp"
#include "Lime.hpp"
#include "Banana.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}


void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    int nbFruit = unsorted.nbFruits();

    for (int i = 0; i < nbFruit; i++) {
        if (typeid(*(unsorted.head()->fruit)) == typeid(Lemon)) {
            if (lemons.isFull() == true)
                unsorted.putFruit(unsorted.pickFruit());
            else {
                lemons.putFruit(unsorted.pickFruit());
                continue;
            }
        }
        if (typeid(*(unsorted.head()->fruit)) == typeid(Banana)) {
            if (bananas.isFull() == true)
                unsorted.putFruit(unsorted.pickFruit());
            else {
                bananas.putFruit(unsorted.pickFruit());
                continue;
            }
        }
        if (typeid(*(unsorted.head()->fruit)) == typeid(Lime)) {
            if (limes.isFull() == true)
                unsorted.putFruit(unsorted.pickFruit());
            else {
                limes.putFruit(unsorted.pickFruit());
                continue;
            }
        }
        unsorted.putFruit(unsorted.pickFruit());
    }
}