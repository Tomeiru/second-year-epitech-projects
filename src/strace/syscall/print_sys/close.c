/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines close
*/

#include "../entries.h"
#include "../print_decimal.h"

int strace_syscall_print_sys_close(struct strace *self,
    struct strace_process *proc)
{
    STRACE_SYSCALL_PRINT_DECIMAL(self, proc->syscall_arguments[0]);
    return (STRACE_SYSCALL_RETVAL_DECODED);
}
