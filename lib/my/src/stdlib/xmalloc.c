/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** Defines xmalloc
*/

#include "my/stdlib.h"
#include "my/internal/stdlib.h"
#include <unistd.h>

void *my_xmalloc(size_t size)
{
    void *result = malloc(size);

    if (result == NULL)
        my_xmalloc_out_of_memory(size);
    return (result);
}
