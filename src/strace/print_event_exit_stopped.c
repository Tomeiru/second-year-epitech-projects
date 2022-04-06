/*
** EPITECH PROJECT, 2022
** strace
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

void strace_print_event_exit_stopped(struct strace *self,
    struct strace_process *proc)
{
    if (!(proc->flags & STRACE_PROCESS_IN_SYSCALL) || (proc->flags &
        (STRACE_PROCESS_FILTERED_SYSCALL | STRACE_PROCESS_HIDE_LOG)))
        return;
    if (self->printing_process != NULL && self->printing_process != proc &&
        self->printing_process->current_column != 0) {
        strace_set_current_process(self, self->printing_process);
        strace_printf(self, " <unfinished ...>\n");
        fflush(stderr);
        self->printing_process->current_column = 0;
        strace_set_current_process(self, proc);
    }
    strace_syscall_print_resume(self, proc);
    if (!(proc->syscall_retval_format & STRACE_SYSCALL_RETVAL_DECODED))
        strace_printf(self, " <unfinished ...>\n");
    self->printing_process = proc;
    strace_printf(self, ") ");
    strace_syscall_print_tab(self);
    strace_printf(self, "= ?\n");
    strace_syscall_print_line_ended(self);
}
