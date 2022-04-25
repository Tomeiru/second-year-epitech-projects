/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** Defines xstrdup
*/

#include "my/string.h"
#include "my/internal/stdlib.h"
#include <string.h>

char *my_xstrdup(const char *string)
{
    char *result = strdup(string);

    if (result == NULL)
        my_xmalloc_out_of_memory(strlen(string) + 1);
    return (result);
}
