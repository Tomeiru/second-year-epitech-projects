/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines do_trace_ret
*/

#include "do_trace_ret.h"
#include "get_regs.h"
#include "printf.h"
#include "syscall/print_leader.h"
#include "print_error_message.h"
#include <sys/ptrace.h>

static bool check_ret(struct ftrace *self, struct ftrace_process *proc)
{
    long instruction = ptrace(PTRACE_PEEKTEXT, proc->pid,
        (void *)self->x86_regs.rip, (void *)NULL);

    if ((instruction & 0xFF) != 0xC3 && (instruction & 0xFF) != 0xCB &&
        (instruction & 0xFF) != 0xC2 && (instruction & 0xFF) != 0xCA)
        return (false);
    if (self->x86_io.iov_len != sizeof(self->x86_regs)) {
        ftrace_print_error_message(self, "Unsupported 32-bit mode of"
            "process PID=%j", (intmax_t)proc->pid);
        return (false);
    }
    return (true);
}

static struct ftrace_symbol *find_symbol(struct ftrace_process *proc,
    uintptr_t address)
{
    struct ftrace_symbol *result = NULL;

    for (size_t i = 0; i < proc->retrieved_symbols->size; ++i)
        if (address > proc->retrieved_symbols->data[i].symbol.st_value &&
            address < proc->retrieved_symbols->data[i].symbol.st_value +
            proc->retrieved_symbols->data[i].symbol.st_size)
            if (result == NULL || result->symbol.st_value <
                proc->retrieved_symbols->data[i].symbol.st_value)
                result = &proc->retrieved_symbols->data[i];
    return (result);
}

int ftrace_do_trace_ret(struct ftrace *self, struct ftrace_process *proc)
{
    struct ftrace_symbol *symbol;

    if (proc->flags & STRACE_PROCESS_HIDE_LOG)
        return (0);
    if (ftrace_get_regs(self, proc) < 0)
        return (-1);
    if (!check_ret(self, proc))
        return (0);
    ftrace_syscall_print_leader(self, proc);
    symbol = find_symbol(proc, self->x86_regs.rip);
    ftrace_printf(self, "Leaving function");
    if (symbol != NULL)
        ftrace_printf(self, " %s", symbol->name);
    ftrace_printf(self, "\n");
    return (1);
}
