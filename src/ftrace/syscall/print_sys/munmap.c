/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines munmap
*/

#include "../entries.h"
#include "../print_address.h"
#include "../print_next_argument.h"
#include "../print_unsigned.h"

int ftrace_syscall_print_sys_munmap(
    struct ftrace *self, struct ftrace_process *proc)
{
    ftrace_syscall_print_address(self, proc->syscall_arguments[0]);
    ftrace_syscall_print_next_argument(self);
    STRACE_SYSCALL_PRINT_UNSIGNED(self, proc->syscall_arguments[1]);
    return (STRACE_SYSCALL_RETVAL_DECODED);
}
