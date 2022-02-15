/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** reallocarray
*/

#include "alloc.h"

void *reallocarray(void *ptr, size_t nmenb, size_t size)
{
    size_t total_size = nmenb * size;

    if (total_size / nmenb != size)
        return (NULL);
    return (realloc(ptr, total_size));
}
