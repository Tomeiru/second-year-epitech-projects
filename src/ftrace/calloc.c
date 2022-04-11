/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines calloc
*/

#include "calloc.h"
#include "die/oom.h"
#include <stdlib.h>

void *ftrace_calloc(struct ftrace *self, size_t num_members, size_t member_size)
{
    void *result = calloc(num_members, member_size);

    if (result == NULL)
        ftrace_die_oom(self);
    return (result);
}
