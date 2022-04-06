/*
** EPITECH PROJECT, 2022
** strace
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

static void sset_part2_do_switch(struct strace *self,
    struct strace_process *proc)
{
    switch (proc->syscall_error) {
    case ERESTARTSYS:
        strace_printf(self, "= ? ERESTARTSYS (To be restarted if SA_RESTART "
            "is set)");
        break;
    case ERESTARTNOINTR:
        strace_printf(self, "= ? ERESTARTNOINTR (To be restarted)");
        break;
    case ERESTARTNOHAND:
        strace_printf(self, "= ? ERESTARTNOHAND (To be restarted if no "
            "handler)");
        break;
    case ERESTART_RESTARTBLOCK:
        strace_printf(self, "= ? ERESTART_RESTARTBLOCK (Interrupted by "
            "signal)");
        break;
    default:
        strace_syscall_print_error_return(self, proc->syscall_retval,
            proc->syscall_error);
    }
}

static int sset_part2(struct strace *self, struct strace_process *proc)
{
    strace_syscall_print_end_arguments(self);
    strace_printf(self, " ");
    strace_syscall_print_tab(self);
    if (strace_process_is_raw(self, proc)) {
        if (proc->syscall_error != 0)
            strace_syscall_print_error_return(self, proc->syscall_retval,
                proc->syscall_error);
        else
            strace_printf(self, "= %#jx", (intmax_t)proc->syscall_retval);
    } else if (proc->syscall_error != 0)
        sset_part2_do_switch(self, proc);
    else
        strace_print_error_message(self, "invalid retval format");
    strace_printf(self, "\n");
    strace_syscall_print_line_ended(self);
    return (0);
}

int strace_syscall_exit_trace(struct strace *self, struct strace_process *proc,
    int r)
{
    int retval_format;

    strace_syscall_print_resume(self, proc);
    self->printing_process = proc;
    if (r != 1) {
        strace_syscall_print_end_arguments(self);
        strace_printf(self, " ");
        strace_syscall_print_tab(self);
        strace_printf(self, "= ? <unavailable>\n");
        strace_syscall_print_line_ended(self);
        return (r);
    }
    if (!strace_process_is_raw(self, proc)) {
        if (proc->syscall_retval_format & STRACE_SYSCALL_RETVAL_DECODED)
            retval_format = proc->syscall_retval_format;
        else
            retval_format = strace_process_get_syscall_entry(proc)->function(
                self, proc);
    }
    return (sset_part2(self, proc));
}
