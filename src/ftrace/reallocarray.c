/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines reallocarray
*/

#include "reallocarray.h"
#include "die/oom.h"
#include <stdlib.h>

void *ftrace_reallocarray(struct ftrace *self, void *ptr, size_t num_members,
    size_t size)
{
    void *result = reallocarray(ptr, num_members, size);

    if (result == NULL)
        ftrace_die_oom(self);
    return (result);
}
