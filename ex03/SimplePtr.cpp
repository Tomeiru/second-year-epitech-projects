/*
** EPITECH PROJECT, 2022
** Day10PM
** File description:
** SimplePtr
*/

#include "SimplePtr.hpp"

SimplePtr::SimplePtr(BaseComponent *rawPtr)
{
    _rawPtr = rawPtr;
}

SimplePtr::~SimplePtr()
{
    if (_rawPtr != nullptr)
        delete (_rawPtr);
}

BaseComponent *SimplePtr::get() const
{
    return (_rawPtr);
}