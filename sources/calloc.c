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
    char *ret;

    if (nmenb == 0 || size == 0)
        return (NULL);
    if (total_size / nmenb != size)
        return (NULL);
    ret = malloc(total_size);
    for (size_t i = 0; i < total_size; i++)
        ret[i] = 0;
    return ((void *)ret);
}
