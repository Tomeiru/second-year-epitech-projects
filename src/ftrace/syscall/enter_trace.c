/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines syscall_enter_trace
*/

#include "enter_trace.h"
#include "print_leader.h"
#include "print_raw_arguments.h"
#include "print_start_arguments.h"
#include "../process/get_syscall_entry.h"
#include "../process/is_raw.h"
#include <stdio.h>
#include <sys/syscall.h>

static int sset_part2(struct ftrace *self, struct ftrace_process *proc)
{
    int result;

    ftrace_syscall_print_leader(self, proc);
    ftrace_syscall_print_start_arguments(
        self, ftrace_process_get_syscall_entry(proc)->name);
    result = ftrace_process_is_raw(self, proc) ?
        ftrace_syscall_print_raw_arguments(self, proc) :
        ftrace_process_get_syscall_entry(proc)->function(self, proc);
    fflush(stderr);
    return (result);
}

int ftrace_syscall_enter_trace(struct ftrace *self, struct ftrace_process *proc)
{
    if (proc->flags & STRACE_PROCESS_HIDE_LOG) {
        switch (ftrace_process_get_syscall_entry(proc)->number) {
        case SYS_execve:
        case SYS_execveat:
            proc->flags &= ~STRACE_PROCESS_HIDE_LOG;
            proc->flags |= STRACE_PROCESS_CHECK_EXEC_SUCCESS;
            break;
        }
    }
    if (proc->flags & STRACE_PROCESS_HIDE_LOG) {
        proc->flags |= STRACE_PROCESS_FILTERED_SYSCALL;
        return (0);
    }
    proc->flags &= ~STRACE_PROCESS_FILTERED_SYSCALL;
    return (sset_part2(self, proc));
}
