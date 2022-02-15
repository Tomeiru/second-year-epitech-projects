/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** calloc
*/

#include "alloc.h"

void *calloc(size_t nmenb, size_t size)
{
    size_t total_size = nmenb * size;

    if (nmenb == 0 || size == 0)
        return (NULL);
    if (total_size / nmenb != size)
        return (NULL);
    return (malloc(nmenb * size));
}