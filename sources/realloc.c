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
    old_data = ptr - sizeof(metadata_t);
    new_data = ret - sizeof(metadata_t);
    memcpy(ret, ptr, (old_data->size >= new_data->size) ? (new_data->size) : (old_data->size));
    return (ret);
}