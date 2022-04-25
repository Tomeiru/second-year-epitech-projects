/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** Defines xcalloc
*/

#include "my/stdlib.h"
#include "my/internal/stdlib.h"

void *my_xcalloc(size_t num_members, size_t size)
{
    void *result = calloc(num_members, size);

    if (result == NULL)
        my_xmalloc_out_of_memory(num_members * size);
    return (result);
}
