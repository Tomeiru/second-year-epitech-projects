/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines exit_decode
*/

#include "exit_decode.h"
#include "get_result.h"

int ftrace_syscall_exit_decode(struct ftrace *self, struct ftrace_process *proc)
{
    if (proc->flags & STRACE_PROCESS_FILTERED_SYSCALL)
        return (0);
    if (proc->flags & STRACE_PROCESS_CHECK_EXEC_SUCCESS)
        proc->flags |= STRACE_PROCESS_HIDE_LOG;
    return (ftrace_syscall_get_result(self, proc));
}
