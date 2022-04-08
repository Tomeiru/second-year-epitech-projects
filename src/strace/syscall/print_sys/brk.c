/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines brk
*/

#include "../entries.h"
#include "../print_address.h"

int strace_syscall_print_sys_brk(struct strace *self,
    struct strace_process *proc)
{
    strace_syscall_print_address(self, proc->syscall_arguments[0]);
    return (STRACE_SYSCALL_RETVAL_DECODED | STRACE_SYSCALL_RETVAL_HEX);
}
