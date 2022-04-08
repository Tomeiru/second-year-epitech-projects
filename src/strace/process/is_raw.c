/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines is_raw
*/

#include "is_raw.h"

bool strace_process_is_raw(struct strace *st, struct strace_process *proc)
{
    return (st->print_raw_arguments ||
        (proc->qualifier_flags & STRACE_QUALIFIER_RAW));
}
