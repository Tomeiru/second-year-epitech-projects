/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc
*/

#include "alloc.h"

void *new_malloc(size_t size, metadata_t *node_prev)
{
    metadata_t *new_metadata = sbrk(0);
    void *ret = NULL;

    if (sbrk(sizeof(metadata_t)) == ((void *)- 1))
        return (NULL);
    new_metadata->next = NULL;
    new_metadata->size = size;
    ret = sbrk(0);
    if (sbrk(size) == ((void *) - 1))
        return (NULL);
    new_metadata->free = 0;
    if (node_prev != NULL && node_prev->next == NULL)
        node_prev->next = new_metadata;
    if (node_prev != NULL && node_prev->next != NULL) {
        new_metadata->next = node_prev->next;
        node_prev->next = new_metadata;
    }return (ret);
}

void *other_malloc(size_t size, void *base_break)
{
    metadata_t *mdata = base_break;
    int best = -1;
    size_t best_backup = -1;

    for (int i = 0 ; mdata->next != NULL; mdata = mdata->next) {
        if (mdata->size > size && size < best_backup && mdata->free == 1) {
            best = i;
            best_backup = mdata->size;
        }
        i++;
    }
    if (best == -1)
        return (new_malloc(size, mdata));
    mdata = base_break;
    for (int i = 0; mdata->next != NULL; mdata = mdata->next) {
        if (best == i)
            break;
    }
    return (new_malloc(size, mdata));
}

void *malloc(size_t size)
{
    static void *base_break = NULL;
    void *ret = NULL;

    if (base_break == NULL) {
        base_break = sbrk(0);
        ret = new_malloc(size, NULL);
        return (ret);
    }
    ret = other_malloc(size, base_break);
    return (ret);
}
