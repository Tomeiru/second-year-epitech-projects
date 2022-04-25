/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** Defines xstrndup
*/

#include "my/string.h"
#include "my/internal/stdlib.h"
#include <string.h>

char *my_xstrndup(const char *string, size_t length)
{
    void *result = strndup(string, length);

    if (result == NULL)
        my_xmalloc_out_of_memory(strnlen(string, length) + 1);
    return (result);
}
