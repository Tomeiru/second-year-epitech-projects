/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** free
*/

#include "alloc.h"

void free(void *ptr)
{
    metadata_t *metadata;

    if (ptr == NULL)
        return;
    metadata = ptr - sizeof(metadata_t);
    if (metadata->magic[0] != -115) {
        write(2, "free(): invalid pointer\n", 24);
        return;
    }
    metadata->free = 1;
    return;
}