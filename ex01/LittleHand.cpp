/*
** EPITECH PROJECT, 2022
** Day10B
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

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
        if (unsorted.head()->fruit->getVitamins() == 3 && unsorted.head()->fruit->getName() == "lemon") {
            if (lemons.isFull() == true)
                unsorted.putFruit(unsorted.pickFruit());
            else {
                lemons.putFruit(unsorted.pickFruit());
                continue;
            }
        }
        if (unsorted.head()->fruit->getVitamins() == 5 && unsorted.head()->fruit->getName() == "banana") {
            if (bananas.isFull() == true)
                unsorted.putFruit(unsorted.pickFruit());
            else {
                bananas.putFruit(unsorted.pickFruit());
                continue;
            }
        }
        if (unsorted.head()->fruit->getVitamins() == 2 && unsorted.head()->fruit->getName() == "lime") {
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