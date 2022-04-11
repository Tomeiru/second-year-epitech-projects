/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines write
*/

#include "../entries.h"
#include "../print_decimal.h"
#include "../print_next_argument.h"
#include "../print_string_n.h"
#include "../print_unsigned.h"

int ftrace_syscall_print_sys_write(
    struct ftrace *self, struct ftrace_process *proc)
{
    STRACE_SYSCALL_PRINT_DECIMAL(self, proc->syscall_arguments[0]);
    ftrace_syscall_print_next_argument(self);
    ftrace_syscall_print_string_n(
        self, proc, proc->syscall_arguments[1], proc->syscall_arguments[2]);
    ftrace_syscall_print_next_argument(self);
    STRACE_SYSCALL_PRINT_UNSIGNED(self, proc->syscall_arguments[2]);
    return (STRACE_SYSCALL_RETVAL_DECODED);
}
