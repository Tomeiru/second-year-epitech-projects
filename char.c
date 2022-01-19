/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** char
*/

#include <stdio.h>
#include "new.h"
#include "char.h"

typedef struct {
    Class base;
    char x;
} CharClass;

static void char_ctor(CharClass *this, va_list *args)
{
    this->x = (char)va_arg(*args, int);
}

static void char_dtor(CharClass *this)
{
    return;
}

static char *char_print(CharClass *this)
{
    char *buff;

    if (!(buff = malloc(sizeof(char) * 11)))
        raise("Out of memory");
    snprintf(buff, 11, "<%s (%c)>", this->base.__name__, this->x);
    return (buff);
}

static CharClass *char_add(CharClass *a, CharClass *b)
{
    return (new(Char, a->x + b->x));
}

static CharClass *char_sub(CharClass *a, CharClass *b)
{

    return (new(Char, a->x - b->x));
}

static CharClass *char_mul(CharClass *a, CharClass *b)
{
    return (new(Char, a->x * b->x));
}

static CharClass *char_div(CharClass *a, CharClass *b)
{
    if (b->x == 0)
        raise("Division by 0");
    return (new(Char, a->x / b->x));
}

static bool char_eq(CharClass *a, CharClass *b)
{
    if (a->x == b->x)
        return (true);
    return (false);
}

static bool char_gt(CharClass *a, CharClass *b)
{
    if (a->x > b->x)
        return (true);
    return (false);
}

static bool char_lt(CharClass *a, CharClass *b)
{
    if (a->x < b->x)
        return (true);
    return (false);
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&char_ctor,
        .__dtor__ = (dtor_t)&char_dtor,
        .__str__ = (to_string_t)&char_print,
        .__add__ = (binary_operator_t)&char_add,
        .__sub__ = (binary_operator_t)&char_sub,
        .__mul__ = (binary_operator_t)&char_mul,
        .__div__ = (binary_operator_t)&char_div,
        .__eq__ = (binary_comparator_t)&char_eq,
        .__gt__ = (binary_comparator_t)&char_gt,
        .__lt__ = (binary_comparator_t)&char_lt
    },
    .x = 0
};

const Class   *Char = (const Class *)&_description;