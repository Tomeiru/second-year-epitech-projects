/*
** EPITECH PROJECT, 2022
** Day10
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "Fruit.hpp"

typedef struct FruitNode_s {
    Fruit *fruit;
    struct FruitNode_s *next;
} FruitNode;

#endif /* !FRUITNODE_HPP_ */
