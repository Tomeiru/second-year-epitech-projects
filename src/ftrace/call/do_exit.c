/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines do_exit
*/

#include "do_exit.h"
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
    if (symbol != NULL)
        ftrace_printf(self, "Entering function %s at %p\n", symbol->name,
            address);
    else
        ftrace_printf(self, "Entering func_%p@%s\n", address,
            ftrace_get_filename_from_addr(self, proc, address));
    proc->flags &= ~STRACE_PROCESS_IN_CALL;
    return (1);
}
