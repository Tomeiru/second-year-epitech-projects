/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** Defines xrealloc
*/

#include "my/stdlib.h"
#include "my/internal/stdlib.h"

void *my_xrealloc(void *ptr, size_t size)
{
    void *result = realloc(ptr, size);

    if (result == NULL && size != 0)
        my_xmalloc_out_of_memory(size);
    return (result);
}
