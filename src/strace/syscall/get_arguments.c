/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines get_arguments
*/

#include "get_arguments.h"

int strace_syscall_get_arguments(struct strace *self,
    struct strace_process *proc)
{
    proc->syscall_arguments[0] = self->x86_regs.rdi;
    proc->syscall_arguments[1] = self->x86_regs.rsi;
    proc->syscall_arguments[2] = self->x86_regs.rdx;
    proc->syscall_arguments[3] = self->x86_regs.r10;
    proc->syscall_arguments[4] = self->x86_regs.r8;
    proc->syscall_arguments[5] = self->x86_regs.r9;
    return (1);
}
