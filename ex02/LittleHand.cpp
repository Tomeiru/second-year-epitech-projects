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

FruitBox * const *LittleHand::organizeCoconut(Coconut const *const *coconuts)
{
    FruitBox **ret;
    int i = 0;
    int boxNumber;
    int a = 0;


    for ( ; coconuts[i] != nullptr; i++);
    boxNumber = i % 6 == 0 ? i / 6 : i / 6 + 1;
    ret = new FruitBox*[boxNumber];
    if (i % 6 == 0) {
        for (int j = 0; j < boxNumber; j++) {
            ret[j] = new FruitBox(6);
            for (int l = 0; l < 6; l++)
                ret[j]->putFruit((Fruit *)coconuts[a++]);
        }
    }
    else {
        for (int j = 0; j < boxNumber - 1; j++) {
            ret[j] = new FruitBox(6);
            for (int l = 0; l < 6; l++)
                ret[j]->putFruit((Fruit *)coconuts[a++]);
        }
        ret[boxNumber - 1] = new FruitBox(i % 6);
        for (int b = 0; b < i % 6; b++)
            ret[boxNumber - 1]->putFruit((Fruit *)coconuts[a++]);
    }
    return ((FruitBox *const *)ret);
}