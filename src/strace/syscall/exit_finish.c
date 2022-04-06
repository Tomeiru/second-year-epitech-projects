/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines exit_finish
*/

#include "exit_finish.h"
#include "../process/free_private_data.h"

void strace_syscall_exit_finish(struct strace *self,
    struct strace_process *proc)
{
    (void)self;
    proc->flags &= ~STRACE_PROCESS_IN_SYSCALL;
    proc->syscall_retval_format = 0;
    strace_process_free_private_data(proc);
}
