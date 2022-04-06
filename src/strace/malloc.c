/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines malloc
*/

#include "malloc.h"
#include "die/oom.h"
#include <stdlib.h>

void *strace_malloc(struct strace *self, size_t size)
{
    void *result = malloc(size);

    if (result == NULL)
        strace_die_oom(self);
    return (result);
}
