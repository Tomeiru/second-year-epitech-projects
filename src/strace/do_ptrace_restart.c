/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines do_ptrace_restart
*/

#include "do_ptrace_restart.h"
#include "print_error_message/errno.h"
#include "syscall/print_line_ended.h"
#include "printf.h"
#include <sys/ptrace.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

int strace_do_ptrace_restart(struct strace *self, unsigned restart_operation,
    struct strace_process *proc, unsigned signal)
{
    int ptrace_errno;

    errno = 0;
    ptrace(restart_operation, proc->pid, 0L, (unsigned long)signal);
    ptrace_errno = errno;
    if (ptrace_errno == 0 || ptrace_errno == ESRCH)
        return (0);
    if (self->current_process != 0 &&
        self->current_process->current_column != 0) {
        strace_printf(self, " <Cannot restart pid %jd with ptrace(%u): %s>\n",
            (intmax_t)proc->pid, restart_operation, strerror(ptrace_errno));
        strace_syscall_print_line_ended(self);
    }
    errno = ptrace_errno;
    strace_print_error_message_errno(self, "ptrace(%u,pid:%jd,sig:%u)",
        restart_operation, proc->pid, signal);
    return (-1);
}
