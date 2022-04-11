/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines is_raw
*/

#include "is_raw.h"

bool ftrace_process_is_raw(struct ftrace *st, struct ftrace_process *proc)
{
    return (st->print_raw_arguments ||
        (proc->qualifier_flags & STRACE_QUALIFIER_RAW));
}
