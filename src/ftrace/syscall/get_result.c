/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines get_result
*/

#include "get_result.h"
#include "get_error.h"
#include "../get_regs.h"

int ftrace_syscall_get_result(struct ftrace *self, struct ftrace_process *proc)
{
    if (ftrace_get_regs(self, proc) < 0)
        return (-1);
    ftrace_syscall_get_error(self, proc, true);
    return (1);
}
