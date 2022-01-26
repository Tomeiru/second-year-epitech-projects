/*
** EPITECH PROJECT, 2022
** Day10PM
** File description:
** RefPtr
*/

#include "RefPtr.hpp"

RefPtr::RefPtr(BaseComponent *rawPtr)
{
    _rawPtr = rawPtr;
}

RefPtr::RefPtr(RefPtr const &other)
{
    _rawPtr = other._rawPtr;
}

RefPtr &RefPtr::operator=(RefPtr const &other)
{
    _rawPtr = other._rawPtr;
}

RefPtr::~RefPtr()
{
    if (_rawPtr != nullptr)
        delete _rawPtr;
}

BaseComponent *RefPtr::get() const
{
    return (_rawPtr);
}