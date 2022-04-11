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
#include "../process/is_raw.h"
#include "../process/get_syscall_entry.h"
#include "../printf.h"
#include "../print_error_message.h"
#include <linux/errno.h>
#include <stdint.h>

static void sset_part2_do_switch(
    struct ftrace *self, struct ftrace_process *proc)
{
    switch (proc->syscall_error) {
    case ERESTARTSYS:
        ftrace_printf(self, "= ? ERESTARTSYS (To be restarted if SA_RESTART "
            "is set)");
        break;
    case ERESTARTNOINTR:
        ftrace_printf(self, "= ? ERESTARTNOINTR (To be restarted)");
        break;
    case ERESTARTNOHAND:
        ftrace_printf(self, "= ? ERESTARTNOHAND (To be restarted if no "
            "handler)");
        break;
    case ERESTART_RESTARTBLOCK:
        ftrace_printf(self, "= ? ERESTART_RESTARTBLOCK (Interrupted by "
            "signal)");
        break;
    default:
        ftrace_syscall_print_error_return(
            self, proc->syscall_retval, proc->syscall_error);
    }
}

static void sset_part2_do_switch2(
    struct ftrace *self, struct ftrace_process *proc, int retval_format)
{
    switch (retval_format & STRACE_SYSCALL_RETVAL_FORMAT_MASK) {
    case STRACE_SYSCALL_RETVAL_UNSIGNED_DECIMAL:
        ftrace_printf(self, "= %ju", (uintmax_t)proc->syscall_retval);
        break;
    case STRACE_SYSCALL_RETVAL_HEX:
        ftrace_printf(self, "= %#jx", (uintmax_t)proc->syscall_retval);
        break;
    case STRACE_SYSCALL_RETVAL_FD:
        ftrace_printf(self, "= %jd", (intmax_t)proc->syscall_retval);
        break;
    default:
        ftrace_print_error_message(self, "invalid retval format");
    }
}

static int sset_part2(
    struct ftrace *self, struct ftrace_process *proc, int retval_format)
{
    ftrace_syscall_print_end_arguments(self);
    ftrace_printf(self, " ");
    ftrace_syscall_print_tab(self);
    if (ftrace_process_is_raw(self, proc)) {
        if (proc->syscall_error != 0)
            ftrace_syscall_print_error_return(
                self, proc->syscall_retval, proc->syscall_error);
        else
            ftrace_printf(self, "= %#jx", (intmax_t)proc->syscall_retval);
    } else if (proc->syscall_error != 0)
        sset_part2_do_switch(self, proc);
    else
        sset_part2_do_switch2(self, proc, retval_format);
    ftrace_printf(self, "\n");
    ftrace_syscall_print_line_ended(self);
    return (0);
}

int ftrace_syscall_exit_trace(
    struct ftrace *self, struct ftrace_process *proc, int r)
{
    int retval_format;

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
    if (!ftrace_process_is_raw(self, proc)) {
        if (proc->syscall_retval_format & STRACE_SYSCALL_RETVAL_DECODED)
            retval_format = proc->syscall_retval_format;
        else
            retval_format =
                ftrace_process_get_syscall_entry(proc)->function(self, proc);
    }
    return (sset_part2(self, proc, retval_format));
}
