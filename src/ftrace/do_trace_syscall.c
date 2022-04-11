/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines do_trace_syscall
*/

#include "do_trace_syscall.h"
#include "syscall/enter_decode.h"
#include "syscall/enter_trace.h"
#include "syscall/enter_finish.h"
#include "syscall/exit_decode.h"
#include "syscall/exit_trace.h"
#include "syscall/exit_finish.h"

int ftrace_do_trace_syscall(struct ftrace *self, struct ftrace_process *proc)
{
    int r;

    if (!(proc->flags & STRACE_PROCESS_IN_SYSCALL)) {
        r = ftrace_syscall_enter_decode(self, proc);
        if (r == 0)
            return (0);
        if (r == 1)
            r = ftrace_syscall_enter_trace(self, proc);
        ftrace_syscall_enter_finish(self, proc, r);
    } else {
        r = ftrace_syscall_exit_decode(self, proc);
        if (r != 0)
            r = ftrace_syscall_exit_trace(self, proc, r);
        ftrace_syscall_exit_finish(self, proc);
    }
    return (r);
}
