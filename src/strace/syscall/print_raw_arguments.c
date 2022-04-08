/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_raw_arguments
*/

#include "print_raw_arguments.h"
#include "../process/get_syscall_entry.h"
#include "print_next_argument.h"
#include "print_hex.h"

int strace_syscall_print_raw_arguments(
    struct strace *self, struct strace_process *proc)
{
    const unsigned num_args =
        strace_process_get_syscall_entry(proc)->num_arguments;

    for (unsigned i = 0; i < num_args; ++i) {
        if (i != 0)
            strace_syscall_print_next_argument(self);
        STRACE_SYSCALL_PRINT_HEX(self, proc->syscall_arguments[i]);
    }
    return (STRACE_SYSCALL_RETVAL_DECODED);
}
