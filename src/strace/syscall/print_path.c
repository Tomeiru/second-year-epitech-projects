/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_path
*/

#include "print_path.h"
#include "print_path_n.h"
#include <limits.h>

int strace_syscall_print_path(struct strace *self, struct strace_process *proc,
    __kernel_ulong_t address)
{
    return (strace_syscall_print_path_n(self, proc, address, PATH_MAX - 1));
}
