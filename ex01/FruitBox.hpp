/*
** EPITECH PROJECT, 2022
** Day10
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox(int size);
        ~FruitBox();
        int nbFruits() const;
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head() const;
        void createList(int, FruitNode **);
        FruitNode *createNode();
        bool isFull();

    protected:
        int _size;
        int _nbFruits;
        bool _full;
        bool _empty;
        FruitNode *_head = nullptr;
    private:
};

#endif /* !FRUITBOX_HPP_ */
