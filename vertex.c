/*
** EPITECH PROJECT, 2022
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "new.h"
#include "vertex.h"

typedef struct {
    Class base;
    int x;
    int y;
    int z;
} VertexClass;

static void vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void vertex_dtor(VertexClass *this)
{
    return;
}

static char *vertex_print(VertexClass *this)
{
    int len = strlen(this->base.__name__) + 11;
    int arr[3] = {
        this->x, this->y, this->z
    };
    int len_num = 0;
    char *buff;

    for (int i = 0; i < 3; i++) {
        if (arr[i] < 0)
            len_num++;
        for ( ; arr[i] != 0; arr[i] /= 10)
            len_num++;
        len += len_num;
        len_num = 0;
    }
    if (!(buff = malloc(sizeof(char) * len)))
        raise("Out of memory");
    snprintf(buff, len, "<%s (%d, %d, %d)>", this->base.__name__, this->x,
    this->y, this->z);
    return (buff);
}

static VertexClass *vertex_add(VertexClass *a, VertexClass *b)
{
    return (new(Vertex, a->x + b->x, a->y + b->y, a->z + b->z));
}

static VertexClass *vertex_sub(VertexClass *a, VertexClass *b)
{

    return (new(Vertex, a->x - b->x, a->y - b->y, a->z - b->z));
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&vertex_ctor,
        .__dtor__ = (dtor_t)&vertex_dtor,
        .__str__ = (to_string_t)&vertex_print,
        .__add__ = (binary_operator_t )&vertex_add,
        .__sub__ = (binary_operator_t )&vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;