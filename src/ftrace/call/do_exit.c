/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines do_exit
*/

#include "do_exit.h"
#include "print_symbol.h"
#include "../get_regs.h"
#include "../printf.h"
#include "../get_symbol_from_addr.h"
#include "../get_filename_from_addr.h"

int ftrace_call_do_exit(struct ftrace *self, struct ftrace_process *proc)
{
    struct ftrace_symbol *symbol;
    void *address = (void *)self->x86_regs.rip;

    if (ftrace_get_regs(self, proc) < 0)
        return (-1);
    symbol = ftrace_get_symbol_from_addr(self, proc, address);
    if ((proc->flags & STRACE_PROCESS_HIDE_CALL_LOG) &&
        proc->symbol_main != NULL && (symbol == NULL || strcmp(symbol->name,
        "main") != 0))
        return (0);
    proc->flags &= ~STRACE_PROCESS_HIDE_CALL_LOG;
    if (symbol != NULL || !(proc->flags & STRACE_PROCESS_CALL_IS_JMP)) {
        ftrace_printf(self, "Entering ");
        ftrace_call_print_symbol(self, proc, symbol, address);
        if (symbol != NULL)
            ftrace_printf(self, " at %p", address);
        ftrace_printf(self, "\n");
    }
    proc->flags &= ~(STRACE_PROCESS_IN_CALL | STRACE_PROCESS_CALL_IS_JMP);
    return (1);
}
