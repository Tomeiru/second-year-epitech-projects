/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines grow_array
*/

#include "grow_array.h"
#include "div_round_up.h"
#include "die/oom.h"
#include "reallocarray.h"
#include <stddef.h>

static const size_t ALLOC_SIZE_DEFAULT = 256;

void *ftrace_grow_array(struct ftrace *self, void *ptr, size_t *num_members,
    size_t member_size)
{
    size_t members_added;

    if (ptr == NULL)
        members_added = *num_members != 0 ? 0 : STRACE_DIV_ROUND_UP(
            ALLOC_SIZE_DEFAULT, member_size);
    else
        members_added = (*num_members >> 1) + 1;
    if ((*num_members + members_added) < *num_members)
        ftrace_die_oom(self);
    *num_members += members_added;
    return (ftrace_reallocarray(self, ptr, *num_members, member_size));
}
