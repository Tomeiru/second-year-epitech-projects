/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines process_do_post_attach
*/

#include "do_post_attach.h"

void strace_process_do_post_attach(
    struct strace *self, struct strace_process *process, unsigned int flags)
{
    (void)self;
    process->flags |= STRACE_PROCESS_ATTACHED |
        STRACE_PROCESS_BEFORE_FIRST_STOP | flags;
}
