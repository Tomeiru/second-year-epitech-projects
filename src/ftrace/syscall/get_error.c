/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines get_error
*/

#include "get_error.h"

bool is_neg_errno(__kernel_ulong_t value)
{
    return (value >= (__kernel_ulong_t)-(__kernel_long_t)4095);
}

void ftrace_syscall_get_error(struct ftrace *self, struct ftrace_process *proc,
    bool check_errno)
{
    int64_t rax = self->x86_regs.rax;

    proc->syscall_error = 0;
    proc->syscall_retval = rax;
    if (check_errno && is_neg_errno(rax)) {
        proc->syscall_retval = -1;
        proc->syscall_error = -rax;
    }
}
