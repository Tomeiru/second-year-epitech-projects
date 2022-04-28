/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines enter_finish
*/

#include "enter_finish.h"

void ftrace_syscall_enter_finish(struct ftrace *self,
    struct ftrace_process *proc, int r)
{
    (void)self;
    proc->flags |= STRACE_PROCESS_IN_SYSCALL;
    proc->syscall_retval_format = r;
}
