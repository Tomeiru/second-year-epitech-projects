/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines reallocarray
*/

#include "reallocarray.h"
#include "die/oom.h"
#include <stdlib.h>

void *strace_reallocarray(
    struct strace *self, void *ptr, size_t num_members, size_t size)
{
    void *result = reallocarray(ptr, num_members, size);

    if (result == NULL)
        strace_die_oom(self);
    return (result);
}
