/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_signal_stop
*/

#include "print_signal_stop.h"
#include "printf.h"
#include "syscall/print_leader.h"
#include "syscall/print_line_ended.h"
#include "sprint_signal_name.h"
#include <stddef.h>

void ftrace_print_signal_stop(struct ftrace *self, struct ftrace_process *proc,
    unsigned int signal)
{
    if (!(proc->flags & STRACE_PROCESS_HIDE_LOG)) {
        ftrace_syscall_print_leader(self, proc);
        ftrace_printf(self, "Received signal %s\n", ftrace_sprint_signal_name(
            self, signal));
        ftrace_syscall_print_line_ended(self);
    }
}
