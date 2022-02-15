/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc
*/

#include "alloc.h"

metadata_t *create_metadata(size_t size, void *base)
{
    metadata_t *new_metadata = base;

    new_metadata->prev = NULL;
    new_metadata->next = NULL;
    new_metadata->size = size;
    new_metadata->free = 0;
    new_metadata->magic[0] = -115;
    return (new_metadata);
}

void *new_malloc(size_t size, size_t pagesize, metadata_t *prev)
{
    size_t pagetocover = ((size + MTDTSIZE) % pagesize == 0) ?
    ((size + MTDTSIZE) / pagesize) : (((size + MTDTSIZE) / pagesize) + 1);
    metadata_t *base_metadata;
    metadata_t *metadata;
    void *base = sbrk(0);

    if (sbrk(pagesize * pagetocover) == ((void *)- 1))
        return (NULL);
    base_metadata = create_metadata(size, base);
    if ((size + MTDTSIZE) % pagesize != 0) {
        metadata = create_metadata((pagesize * pagetocover) -
        size - MTDTSIZE * 2, base + MTDTSIZE + size);
        base_metadata->next = metadata;
        metadata->prev = base_metadata;
    }
    if (prev != NULL) {
        prev->next = base_metadata;
        base_metadata->prev = prev;
    }metadata->free = 1;
    return (base + MTDTSIZE);
}

void *insert_malloc(size_t size, metadata_t *prev)
{
    void *ret = (void *) prev + MTDTSIZE;
    metadata_t *new_metadata;

    prev->free = 0;
    if (prev->size <= size + MTDTSIZE)
        return (ret);
    new_metadata = create_metadata(prev->size - MTDTSIZE - size,
    ret + size);
    new_metadata->free = 1;
    prev->size = size;
    new_metadata->next = prev->next;
    if (prev->next != NULL)
        prev->next->prev = new_metadata;
    new_metadata->prev = prev;
    prev->next = new_metadata;
    return (ret);
}

void *other_malloc(size_t size, void *base_break, size_t pagesize)
{
    metadata_t *mdata = base_break;
    int best = -1;
    size_t best_backup = -1;

    for (int i = 0 ; mdata != NULL; mdata = mdata->next) {
        if (mdata->size >= size && mdata->size < best_backup &&
        mdata->free == 1) {
            best = i;
            best_backup = mdata->size;
        }
        i++;
    }
    if (best == -1)
        return (new_malloc(size, pagesize, mdata));
    mdata = base_break;
    for (int i = 0; mdata != NULL; mdata = mdata->next)
        if (best == i++)
            break;
    return (insert_malloc(size, mdata));
}

void *malloc(size_t size)
{
    static void *base_break = NULL;
    void *ret = NULL;
    size_t aligned_size = ALIGN(size);
    size_t pagesize = getpagesize() * 2;

    if (size == 0)
        return (NULL);
    if (base_break == NULL) {
        base_break = sbrk(0);
        ret = new_malloc(aligned_size, pagesize, NULL);
        return (ret);
    }
    ret = other_malloc(aligned_size, base_break, pagesize);
    return (ret);
}
