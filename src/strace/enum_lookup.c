/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines enum_lookup
*/

#include "enum_lookup.h"
#include <stddef.h>

const char *strace_enum_lookup(const struct strace_enum *enu, uintmax_t value)
{
    if (enu == NULL || enu->data == NULL)
        return (NULL);
    for (size_t i = 0; i < enu->size; ++i)
        if (enu->data[i].value == value)
            return (enu->data[i].string);
    return (NULL);
}
