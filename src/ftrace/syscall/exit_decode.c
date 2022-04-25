/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines exit_decode
*/

#include "exit_decode.h"
#include "get_result.h"
#include "../process/get_syscall_entry.h"

int ftrace_syscall_exit_decode(struct ftrace *self, struct ftrace_process *proc)
{
    if (ftrace_process_get_syscall_entry(proc)->flags &
        STRACE_SYSCALL_ENTRY_MEMORY_MAPPING_CHANGE)
        proc->proc_maps_up_to_date = false;
    if (proc->flags & STRACE_PROCESS_FILTERED_SYSCALL)
        return (0);
    if (proc->flags & STRACE_PROCESS_CHECK_EXEC_SUCCESS)
        proc->flags |= STRACE_PROCESS_HIDE_LOG;
    return (ftrace_syscall_get_result(self, proc));
}
