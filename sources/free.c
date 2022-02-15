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
    //if (metadata->magic[0] != -115) {
        //write(2, "free(): invalid pointer\n", 24);
        //return;
    //}
    metadata->free = 1;
    if (metadata->next != NULL && metadata->next->free == 1) {
        metadata->size = metadata->next->size + sizeof(metadata_t) + metadata->size;
        metadata->next = metadata->next->next;
        if (metadata->next->next != NULL)
            metadata->next->next->prev = metadata;
    }if (metadata->prev != NULL && metadata->prev->free == 1) {
        metadata->prev->size = metadata->prev->size + sizeof(metadata_t) + metadata->size;
        metadata->prev->next = metadata->next;
        if (metadata->next != NULL)
            metadata->next->prev = metadata->prev;
        metadata = metadata->prev;
    }return;
}