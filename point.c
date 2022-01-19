/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "new.h"
#include "point.h"

typedef struct {
    Class base;
    int x;
    int y;
} PointClass;

static void point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void point_dtor(PointClass *this)
{
    return;
}

static char *point_print(PointClass *this)
{
    int len = strlen(this->base.__name__) + 11;
    int arr[2] = {
        this->x, this->y
    };
    int len_num = 0;
    char *buff;

    for (int i = 0; i < 2; i++) {
        if (arr[i] < 0)
            len_num++;
        for ( ; arr[i] != 0; arr[i] /= 10)
            len_num++;
        len += len_num;
        len_num = 0;
    }
    if (!(buff = malloc(sizeof(char) * len)))
        raise("Out of memory");
    snprintf(buff, len, "<%s (%d, %d)>", this->base.__name__, this->x, this->y);
    return (buff);
}

static PointClass *point_add(PointClass *a, PointClass *b)
{
    return (new(Point, a->x + b->x, a->y + b->y));
}

static PointClass *point_sub(PointClass *a, PointClass *b)
{
    return (new(Point, a->x - b->x, a->y - b->y));
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&point_ctor,
        .__dtor__ = (dtor_t)&point_dtor,
        .__str__ = (to_string_t)&point_print,
        .__add__ = (binary_operator_t )&point_add,
        .__sub__ = (binary_operator_t )&point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
