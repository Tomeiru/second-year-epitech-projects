/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** RUSH2 float class
*/

#include <stdio.h>
#include "new.h"
#include "float.h"

typedef struct {
    Class base;
    float x;
} FloatClass;

static void float_ctor(FloatClass *this, va_list *args)
{
    this->x = (float)va_arg(*args, double);
}

static void float_dtor(FloatClass *this)
{
    return;
}

static char *float_print(FloatClass *this)
{
    int len = strlen(this->base.__name__) + 11;
    int num = this->x;
    int len_num = 7;
    char *buff;

    if (num <= 0)
        len_num++;
    for ( ; num != 0; num /= 10)
        len_num++;
    len += len_num;
    len_num = 7;
    if (!(buff = malloc(sizeof(char) * len)))
        raise("Out of memory");
    snprintf(buff, len, "<%s (%.6f)>", this->base.__name__, this->x);
    return (buff);
}

static FloatClass *float_add(FloatClass *a, FloatClass *b)
{
    return (new(Float, a->x + b->x));
}

static FloatClass *float_sub(FloatClass *a, FloatClass *b)
{
    return (new(Float, a->x - b->x));
}

static FloatClass *float_mul(FloatClass *a, FloatClass *b)
{
    return (new(Float, a->x * b->x));
}

static FloatClass *float_div(FloatClass *a, FloatClass *b)
{
    if (b->x == 0)
        raise("Division by 0");
    return (new(Float, a->x / b->x));
}

static bool float_eq(FloatClass *a, FloatClass *b)
{
    if ((a->x - 0.000001) < b->x && (a->x + 0.000001) > b->x)
        return (true);
    return (false);
}

static bool float_gt(FloatClass *a, FloatClass *b)
{
    if (a->x > b->x)
        return (true);
    return (false);
}

static bool float_lt(FloatClass *a, FloatClass *b)
{
    if (a->x < b->x)
        return (true);
    return (false);
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&float_ctor,
        .__dtor__ = (dtor_t)&float_dtor,
        .__str__ = (to_string_t)&float_print,
        .__add__ = (binary_operator_t)&float_add,
        .__sub__ = (binary_operator_t)&float_sub,
        .__mul__ = (binary_operator_t)&float_mul,
        .__div__ = (binary_operator_t)&float_div,
        .__eq__ = (binary_comparator_t)&float_eq,
        .__gt__ = (binary_comparator_t)&float_gt,
        .__lt__ = (binary_comparator_t)&float_lt
    },
    .x = 0,
};

const Class   *Float = (const Class *)&_description;
