/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines exit_trace
*/

#include "exit_trace.h"
#include "print_resume.h"
#include "print_end_arguments.h"
#include "print_tab.h"
#include "print_line_ended.h"
#include "print_error_return.h"
#include "../process/get_syscall_entry.h"
#include "../printf.h"
#include "../print_error_message.h"
#include <linux/errno.h>
#include <stdint.h>

static int sset_part2(
    struct ftrace *self, struct ftrace_process *proc)
{
    ftrace_syscall_print_end_arguments(self);
    ftrace_printf(self, " ");
    ftrace_syscall_print_tab(self);
    if (proc->syscall_error != 0)
        ftrace_syscall_print_error_return(
            self, proc->syscall_retval, proc->syscall_error);
    else
        ftrace_printf(self, "= %#jx", (intmax_t)proc->syscall_retval);
    ftrace_printf(self, "\n");
    ftrace_syscall_print_line_ended(self);
    return (0);
}

int ftrace_syscall_exit_trace(
    struct ftrace *self, struct ftrace_process *proc, int r)
{
    ftrace_syscall_print_resume(self, proc);
    self->printing_process = proc;
    if (r != 1) {
        ftrace_syscall_print_end_arguments(self);
        ftrace_printf(self, " ");
        ftrace_syscall_print_tab(self);
        ftrace_printf(self, "= ? <unavailable>\n");
        ftrace_syscall_print_line_ended(self);
        return (r);
    }
    return (sset_part2(self, proc));
}
