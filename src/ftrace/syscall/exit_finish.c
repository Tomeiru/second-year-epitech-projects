/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines exit_finish
*/

#include "exit_finish.h"
#include "../process/free_private_data.h"

void ftrace_syscall_exit_finish(struct ftrace *self,
    struct ftrace_process *proc)
{
    (void)self;
    proc->flags &= ~STRACE_PROCESS_IN_SYSCALL;
    proc->syscall_retval_format = 0;
    ftrace_process_free_private_data(proc);
}
