/*
** EPITECH PROJECT, 2022
** Day12
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_

#include <iostream>

template<typename type>
void swap(type &a, type &b)
{
    type c = a;

    a = b;
    b = c;
}

template<typename type>
type min(type a, type b)
{
    return (a < b ? a : b);
}

template<typename type>
type max(type a, type b)
{
    return (a < b ? b : a);
}

template<typename type>
type clamp(type value, type min, type max)
{
    if (value < min)
        return (min);
    if (max < value)
        return (max);
    return (value);
}

#endif /* !ALGORITHM_HPP_ */
