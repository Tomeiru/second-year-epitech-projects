/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "array.h"
#include "new.h"

typedef struct {
    Container base;
    Class *_type;
    size_t _size;
    Object **_tab;
} ArrayClass;

typedef struct {
    Iterator base;
    ArrayClass *_array;
    size_t _idx;
} ArrayIteratorClass;

static void array_iterator_ctor(ArrayIteratorClass *this, va_list *args)
{
    this->_array = va_arg(*args, ArrayClass *);
    this->_idx = va_arg(*args, int);
}

static bool array_iterator_eq(ArrayIteratorClass *this,
ArrayIteratorClass *other)
{
    return (this->_idx == other->_idx);
}

static bool array_iterator_gt(ArrayIteratorClass *this,
ArrayIteratorClass *other)
{
    return (this->_idx > other->_idx);
}

static bool array_iterator_lt(ArrayIteratorClass *this,
ArrayIteratorClass *other)
{
    return (this->_idx < other->_idx);
}

static void array_iterator_incr(ArrayIteratorClass *this)
{
    this->_idx += 1;
}

static Object *array_iterator_getval(ArrayIteratorClass *this)
{
    if (this->_idx >= this->_array->_size)
        raise("Out of range");
    return (this->_array->_tab[this->_idx]);
}

static void array_iterator_setval(ArrayIteratorClass *this, ...)
{
    va_list args;

    if (this->_idx >= this->_array->_size)
        raise("Out of range");
    va_start(args, this);
    free(this->_array->_tab[this->_idx]);
    this->_array->_tab[this->_idx] = va_new(this->_array->_type, &args);
    va_end(args);
}

static const ArrayIteratorClass ArrayIteratorDescr = {
    {
        {
            .__size__ = sizeof(ArrayIteratorClass),
            .__name__ = "ArrayIterator",
            .__ctor__ = (ctor_t)&array_iterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&array_iterator_eq,
            .__gt__ = (binary_comparator_t)&array_iterator_gt,
            .__lt__ = (binary_comparator_t)&array_iterator_lt,
        },
        .__incr__ = (incr_t)&array_iterator_incr,
        .__getval__ = (getval_t)&array_iterator_getval,
        .__setval__ = (setval_t)&array_iterator_setval,
    },
    ._array = NULL,
    ._idx = 0
};

static const Class *ArrayIterator = (const Class *)&ArrayIteratorDescr;

static void array_ctor(ArrayClass *this, va_list *args)
{
    va_list *temp = malloc(sizeof(va_list));

    this->_size = va_arg(*args, size_t);
    this->_type = va_arg(*args, Class *);
    this->_tab = malloc(sizeof(Object *) * this->_size);
    va_copy(*temp, *args);
    for (int i = 0; i < this->_size; i++) {
        va_copy(*args, *temp);
        this->_tab[i] = va_new(this->_type, args);
    }
    free(temp);
}

static void array_dtor(ArrayClass *this)
{
    for (unsigned int i = 0; i < this->_size; i++)
        delete(this->_tab[i]);
    free(this->_tab);
}

static size_t array_len(ArrayClass *this)
{
    return (this->_size);
}

static Iterator *array_begin(ArrayClass *this)
{
    return (new(ArrayIterator, this, 0));
}

static Iterator *array_end(ArrayClass *this)
{
    return (new(ArrayIterator, this, this->_size));
}

static Object *array_getitem(ArrayClass *this, ...)
{
    va_list args;
    size_t index;

    va_start(args, this);
    index = va_arg(args, size_t);
    va_end(args);
    if (index >= this->_size)
        raise("Out of range");
    return (this->_tab[index]);
}

static void array_setitem(ArrayClass *this, ...)
{
    va_list args;
    size_t index;

    va_start(args, this);
    index = va_arg(args, size_t);
    if (index >= this->_size) {
        va_end(args);
        raise("Out of range");
    }
    free(this->_tab[index]);
    this->_tab[index] = va_new(this->_type, &args);
    va_end(args);
}

static const ArrayClass _descr = {
    {
        {
            .__size__ = sizeof(ArrayClass),
            .__name__ = "Array",
            .__ctor__ = (ctor_t)&array_ctor,
            .__dtor__ = (dtor_t)&array_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&array_len,
        .__begin__ = (iter_t)&array_begin,
        .__end__ = (iter_t)&array_end,
        .__getitem__ = (getitem_t)&array_getitem,
        .__setitem__ = (setitem_t)&array_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._tab = NULL
};

const Class *Array = (const Class *)&_descr;
