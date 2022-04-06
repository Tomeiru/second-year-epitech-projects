/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines get_result
*/

#include "get_result.h"
#include "get_error.h"
#include "../get_regs.h"

int strace_syscall_get_result(struct strace *self, struct strace_process *proc)
{
    if (strace_get_regs(self, proc) < 0)
        return (-1);
    strace_syscall_get_error(self, proc, true);
    return (1);
}
