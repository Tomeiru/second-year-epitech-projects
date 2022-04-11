/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines brk
*/

#include "../entries.h"
#include "../print_address.h"

int ftrace_syscall_print_sys_brk(
    struct ftrace *self, struct ftrace_process *proc)
{
    ftrace_syscall_print_address(self, proc->syscall_arguments[0]);
    return (STRACE_SYSCALL_RETVAL_DECODED | STRACE_SYSCALL_RETVAL_HEX);
}
