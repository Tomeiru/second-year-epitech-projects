/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines get_regs
*/

#include "get_regs.h"
#include <sys/ptrace.h>
#include <elf.h>

static long do_getregset(struct ftrace *self, pid_t pid)
{
    self->x86_io.iov_len = sizeof(self->x86_regs);
    return (ptrace(PTRACE_GETREGSET, pid, NT_PRSTATUS, &self->x86_io));
}

long ftrace_get_regs(struct ftrace *self, struct ftrace_process *proc)
{
    return (do_getregset(self, proc->pid));
}
