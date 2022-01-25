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
    returnNode->_name = "";
    returnNode->_vitamines = 0;
    return (returnNode);
}

void FruitBox::createList(int size, FruitNode **_ptr)
{
    FruitNode *temp;
    FruitNode *temp_second;

    if (size == 0) {
        *_ptr = nullptr;
        return;
    }
    temp = createNode();
    *_ptr = temp;
    for (int i = 1; i < size; i++) {
        temp->next = createNode();
        temp = temp->next;
    }
}

FruitBox::FruitBox(int size)
{
    _size = size;
    _nbFruits = 0;
    _full = false;
    _empty = true;
    _head = nullptr;

    createList(size, &_head);
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
        _head->fruit = f;
        _head->_vitamines = f->getVitamins();
        _head->_name = f->getName();
        _nbFruits += 1;
        _empty = false;
        if (_size == 1)
            _full = true;
        return (true);
    }
    for ( ; temp->fruit != nullptr ; temp = temp->next) {
        if (temp->fruit == f)
            return (false);
    }
    temp->fruit = f;
    temp->_vitamines = f->getVitamins();
    temp->_name = f->getName();
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

    if (_empty == true || _head == nullptr || _size == 0)
        return (nullptr);
    if (_nbFruits == 1) {
        _head->next = createNode();
        ret = _head->fruit;
        temp = _head;
        _head = _head->next;
        delete temp;
        _nbFruits -= 1;
        _empty = true;
        _full = false;
        return (ret);
    }
    temp = _head;
    ret = _head->fruit;
    _head = _head->next;
    _nbFruits -= 1;
    temp_second = _head;
    _full = false;
    for ( ; temp_second->next != nullptr; temp_second = temp_second->next);
    temp_second->next = createNode();
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