/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_signal_stop
*/

#include "print_signal_stop.h"
#include "printf.h"
#include "syscall/print_leader.h"
#include "syscall/print_line_ended.h"
#include "sprint_signal_name.h"
#include <stddef.h>

// TODO (do we need to do anything about this, actually ?)
void strace_print_signal_stop(struct strace *self, struct strace_process *proc,
    const siginfo_t *signal_info, unsigned int signal)
{
    if (!(proc->flags & STRACE_PROCESS_HIDE_LOG)) {
        strace_syscall_print_leader(self, proc);
        if (signal_info != NULL) {
            strace_printf(
                self, "--- %s ", strace_sprint_signal_name(self, signal));
            strace_printf(self, "TODO: print signal info");
            strace_printf(self, " ---\n");
        } else
            strace_printf(self, "--- stopped by %s ---\n",
                strace_sprint_signal_name(self, signal));
        strace_syscall_print_line_ended(self);
    }
}
