/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines close
*/

#include "../entries.h"
#include "../print_decimal.h"

int ftrace_syscall_print_sys_close(
    struct ftrace *self, struct ftrace_process *proc)
{
    STRACE_SYSCALL_PRINT_DECIMAL(self, proc->syscall_arguments[0]);
    return (STRACE_SYSCALL_RETVAL_DECODED);
}
