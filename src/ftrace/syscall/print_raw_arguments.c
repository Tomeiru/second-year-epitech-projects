/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_raw_arguments
*/

#include "print_raw_arguments.h"
#include "../process/get_syscall_entry.h"
#include "print_next_argument.h"
#include "print_hex.h"

int ftrace_syscall_print_raw_arguments(struct ftrace *self,
    struct ftrace_process *proc)
{
    const unsigned num_args =
        ftrace_process_get_syscall_entry(proc)->num_arguments;

    for (unsigned i = 0; i < num_args; ++i) {
        if (i != 0)
            ftrace_syscall_print_next_argument(self);
        STRACE_SYSCALL_PRINT_HEX(self, proc->syscall_arguments[i]);
    }
    return (STRACE_SYSCALL_RETVAL_DECODED);
}
