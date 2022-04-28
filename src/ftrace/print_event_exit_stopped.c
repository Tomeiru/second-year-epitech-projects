/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_event_exit_stopped
*/

#include "print_event_exit_stopped.h"
#include "printf.h"
#include "set_current_process.h"
#include "syscall/print_line_ended.h"
#include "syscall/print_resume.h"
#include "syscall/print_tab.h"
#include <stdio.h>
#include <stddef.h>

void ftrace_print_event_exit_stopped(struct ftrace *self,
    struct ftrace_process *proc)
{
    if (!(proc->flags & STRACE_PROCESS_IN_SYSCALL) || (proc->flags &
        (STRACE_PROCESS_FILTERED_SYSCALL | STRACE_PROCESS_HIDE_LOG)))
        return;
    if (self->printing_process != NULL && self->printing_process != proc &&
        self->printing_process->current_column != 0) {
        ftrace_set_current_process(self, self->printing_process);
        ftrace_printf(self, " <unfinished ...>\n");
        fflush(stderr);
        self->printing_process->current_column = 0;
        ftrace_set_current_process(self, proc);
    }
    ftrace_syscall_print_resume(self, proc);
    if (!(proc->syscall_retval_format & STRACE_SYSCALL_RETVAL_DECODED))
        ftrace_printf(self, " <unfinished ...>\n");
    self->printing_process = proc;
    ftrace_printf(self, ") ");
    ftrace_syscall_print_tab(self);
    ftrace_printf(self, "= ?\n");
    ftrace_syscall_print_line_ended(self);
}
