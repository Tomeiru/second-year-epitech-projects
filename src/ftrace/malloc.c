/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines malloc
*/

#include "malloc.h"
#include "die/oom.h"
#include <stdlib.h>

void *ftrace_malloc(struct ftrace *self, size_t size)
{
    void *result = malloc(size);

    if (result == NULL)
        ftrace_die_oom(self);
    return (result);
}
