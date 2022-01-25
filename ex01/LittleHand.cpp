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

    for (int i = 0; i < nbFruit - 1; i++) {
        if (unsorted.head()->_vitamines == 3 && unsorted.head()->_name == "lemon") {
            if (lemons.isFull() == true)
                unsorted.putFruit(unsorted.pickFruit());
            else {
                lemons.putFruit(unsorted.pickFruit());
                continue;
            }
        }
        if (unsorted.head()->_vitamines == 5 && unsorted.head()->_name == "banana") {
            if (bananas.isFull() == true) {
                unsorted.putFruit(unsorted.pickFruit());
            }
            else {
                bananas.putFruit(unsorted.pickFruit());
                continue;
            }
        }
        if (unsorted.head()->_vitamines == 2 && unsorted.head()->_name == "lime") {
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