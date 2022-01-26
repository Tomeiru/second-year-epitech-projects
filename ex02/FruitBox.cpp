/*
** EPITECH PROJECT, 2022
** Day10
** File description:
** FruitBox
*/

#include "FruitBox.hpp"


FruitNode *FruitBox::createNode()
{
    FruitNode *returnNode = new FruitNode();

    returnNode->fruit = nullptr;
    returnNode->next = nullptr;
    return (returnNode);
}

FruitBox::FruitBox(int size)
{
    _size = size;
    _nbFruits = 0;
    _full = false;
    _empty = true;
    _head = nullptr;
    if (_size == 0)
        return;
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const
{
    return (_nbFruits);
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *temp = _head;

    if (_full == true || _size == 0)
        return (false);
    if (_empty == true) {
        _head = createNode();
        _head->fruit = f;
        _nbFruits += 1;
        _empty = false;
        if (_size == 1)
            _full = true;
        return (true);
    }
    for ( ; temp->next != nullptr ; temp = temp->next) {
        if (temp->fruit == f)
            return (false);
    }
    temp->next = createNode();
    temp->next->fruit = f;
    _nbFruits += 1;
    if (_nbFruits == _size)
        _full = true;
    return (true);
}

Fruit *FruitBox::pickFruit()
{
    Fruit *ret = nullptr;
    FruitNode *temp;
    FruitNode *temp_second;

    if (_empty == true || _nbFruits == 0 || _head == nullptr || _size == 0)
        return (nullptr);
    if (_nbFruits == 1) {
        ret = _head->fruit;
        temp = _head;
        _head = nullptr;
        delete temp;
        _nbFruits -= 1;
        _empty = true;
        _full = false;
        return (ret);
    }
    ret = _head->fruit;
    _head = _head->next;
    _nbFruits -= 1;
    _full = false;
    return (ret);
}

FruitNode *FruitBox::head() const
{
    return (_head);
}

bool FruitBox::isFull()
{
    return (_full);
}