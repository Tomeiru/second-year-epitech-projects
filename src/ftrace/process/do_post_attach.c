/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines process_do_post_attach
*/

#include "do_post_attach.h"

void ftrace_process_do_post_attach(struct ftrace *self,
    struct ftrace_process *process, unsigned int flags)
{
    (void)self;
    process->flags |= STRACE_PROCESS_ATTACHED |
        STRACE_PROCESS_BEFORE_FIRST_STOP | flags;
}
