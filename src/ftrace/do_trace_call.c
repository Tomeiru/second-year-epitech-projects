/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines do_trace_call
*/

#include "do_trace_call.h"
#include "get_regs.h"
#include "print_error_message.h"
#include "syscall/print_leader.h"
#include "call/do_exit.h"
#include "printf.h"
#include <sys/ptrace.h>

static bool check_call(struct ftrace *self, struct ftrace_process *proc)
{
    unsigned long instruction = ptrace(PTRACE_PEEKTEXT, proc->pid,
        (void *)self->x86_regs.rip, (void *)NULL);

    while ((instruction & 0xFF) == 0xF2 || (instruction & 0xFF) == 0x41)
        instruction >>= 8;
    if ((instruction & 0xFF) == 0xEB || (instruction & 0xFF) == 0xE9 ||
        (instruction & 0xFF) == 0xEA || (instruction & 0xFF) == 0xEA)
        proc->flags |= STRACE_PROCESS_CALL_IS_JMP;
    else if ((instruction & 0xFF) != 0xE8 && (instruction & 0xFF) != 0xFF &&
        (instruction & 0xFF) != 0x9A)
        return (false);
    if (self->x86_io.iov_len != sizeof(self->x86_regs)) {
        ftrace_print_error_message(self, "Unsupported 32-bit mode of"
            "process PID=%j", (intmax_t)proc->pid);
        return (false);
    }
    return (true);
}

int ftrace_do_trace_call(struct ftrace *self, struct ftrace_process *proc)
{
    if (proc->flags & STRACE_PROCESS_HIDE_LOG)
        return (0);
    if (!(proc->flags & STRACE_PROCESS_IN_CALL)) {
        if (ftrace_get_regs(self, proc) < 0)
            return (-1);
        if (!check_call(self, proc))
            return (0);
        ftrace_syscall_print_leader(self, proc);
        proc->flags |= STRACE_PROCESS_IN_CALL;
        return (1);
    } else
        return (ftrace_call_do_exit(self, proc));
}
