/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** int
*/

#include <stdio.h>
#include "new.h"
#include "int.h"

typedef struct {
    Class base;
    int x;
} IntClass;

static void int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void int_dtor(IntClass *this)
{
    return;
}

static char *int_print(IntClass *this)
{
    int len = strlen(this->base.__name__) + 6;
    int num = this->x;
    int len_num = 0;
    char *buff;

    if (num < 0)
        len_num++;
    for ( ; num != 0; num /= 10)
        len_num++;
    len += len_num;
    len_num = 0;
    if (!(buff = malloc(sizeof(char) * len)))
        raise("Out of memory");
    snprintf(buff, len, "<%s (%d)>", this->base.__name__, this->x);
    return (buff);
}

static IntClass *int_add(IntClass *a, IntClass *b)
{
    return (new(Int, a->x + b->x));
}

static IntClass *int_sub(IntClass *a, IntClass *b)
{
    return (new(Int, a->x - b->x));
}

static IntClass *int_mul(IntClass *a, IntClass *b)
{
    return (new(Int, a->x * b->x));
}

static IntClass *int_div(IntClass *a, IntClass *b)
{
    if (b->x == 0)
        raise("Division by 0");
    return (new(Int, a->x * b->x));
}

static bool int_eq(IntClass *a, IntClass *b)
{
    if (a->x == b->x)
        return (true);
    return (false);
}

static bool int_lt(IntClass *a, IntClass *b)
{
    if (a->x < b->x)
        return (true);
    return (false);
}

static bool int_gt(IntClass *a, IntClass *b)
{
    if (a->x > b->x)
        return (true);
    return (false);
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&int_ctor,
        .__dtor__ = (dtor_t)&int_dtor,
        .__str__ = (to_string_t)&int_print,
        .__add__ = (binary_operator_t)&int_add,
        .__sub__ = (binary_operator_t)&int_sub,
        .__mul__ = (binary_operator_t)&int_mul,
        .__div__ = (binary_operator_t)&int_div,
        .__eq__ = (binary_comparator_t)&int_eq,
        .__gt__ = (binary_comparator_t)&int_gt,
        .__lt__ = (binary_comparator_t)&int_lt
    },
    .x = 0
};

const Class *Int = (const Class *)&_description;
