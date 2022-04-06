/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_arguments_decimal
*/

#include "entries.h"
#include "print_next_argument.h"
#include "print_decimal.h"
#include "../process/get_syscall_entry.h"

int strace_syscall_print_arguments_decimal(struct strace *self,
    struct strace_process *proc)
{
    const size_t num_arguments = strace_process_get_syscall_entry(
        proc)->num_arguments;

    for (size_t i = 0; i < num_arguments; ++i) {
        if (i != 0)
            strace_syscall_print_next_argument(self);
        STRACE_SYSCALL_PRINT_DECIMAL(self, (int)proc->syscall_arguments[i]);
    }
    return (STRACE_SYSCALL_RETVAL_DECODED);
}
