/*
** EPITECH PROJECT, 2022
** Day12
** File description:
** Array
*/

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <exception>
#include <vector>
#include <iostream>
#include <functional>

template<typename type, std::size_t sizetype>

class Array {
    public:
        Array() : _array(std::vector<type>(sizetype)) {};
        type &operator[](const std::size_t pos);
        const type &operator[](const std::size_t pos) const;
        void forEach(const std::function<void(const type&)>& task) const;
        std::size_t size() const;
        template <typename U>
        Array<U, sizetype> convert(const std::function<U(const type&)>& converter) const;

    protected:
        std::vector<type> _array;
    private:
};



template<typename type, std::size_t sizetype>
type &Array<type, sizetype>::operator[](const std::size_t pos)
{
    if (pos >= sizetype)
        throw std::invalid_argument("Out of range");
    return (_array[pos]);
}

template<typename type, std::size_t sizetype>
const type &Array<type, sizetype>::operator[](const std::size_t pos) const
{
    if (pos >= sizetype)
        throw std::invalid_argument("Out of range");
    return (_array[pos]);
}

template<typename type, std::size_t sizetype>
std::size_t Array<type, sizetype>::size() const
{
    return (sizetype);
}

template<typename type, std::size_t sizetype>
std::ostream &operator<<(std::ostream &os, const Array<type, sizetype> &other)
{
    os << "[";
    int i = 0;

    for ( ; i < sizetype - 1; i++)
        os << other[i] << ", ";
    os << other[i] << "]";
    return (os);
}

template<typename type, std::size_t sizetype>
void Array<type, sizetype>::forEach(const std::function<void(const type&)>& task) const
{
    for (int i = 0; i < sizetype; i++)
        task(_array[i]);
}

template<typename type, std::size_t sizetype>
template <typename U>
Array<U, sizetype> Array<type, sizetype>::convert(const std::function<U(const type&)>& converter) const
{
    Array<U, sizetype> ret;
    for (int i = 0; i < sizetype; i++)
        ret[i] = converter(_array[i]);
    return (ret);
}

#endif /* !ARRAY_HPP_ */
