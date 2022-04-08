/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines enter_finish
*/

#include "enter_finish.h"

void strace_syscall_enter_finish(
    struct strace *self, struct strace_process *proc, int r)
{
    (void)self;
    proc->flags |= STRACE_PROCESS_IN_SYSCALL;
    proc->syscall_retval_format = r;
}
