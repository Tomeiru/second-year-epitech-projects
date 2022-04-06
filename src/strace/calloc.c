/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines calloc
*/

#include "calloc.h"
#include "die/oom.h"
#include <stdlib.h>

void *strace_calloc(struct strace *self, size_t num_members, size_t member_size)
{
    void *result = calloc(num_members, member_size);

    if (result == NULL)
        strace_die_oom(self);
    return (result);
}
