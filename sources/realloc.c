/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** realloc
*/

#include "alloc.h"

void *realloc(void *ptr, size_t size)
{
    void *ret;
    metadata_t *old_data;
    metadata_t *new_data;

    if (ptr == NULL)
        return (malloc(size));
    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    free(ptr);
    ret = malloc(size);
    if (ret == NULL)
        return (NULL);
    old_data = ptr - MTDTSIZE;
    new_data = ret - MTDTSIZE;
    memcpy(ret, ptr, (old_data->size >= new_data->size) ? (new_data->size) :
    (old_data->size));
    return (ret);
}