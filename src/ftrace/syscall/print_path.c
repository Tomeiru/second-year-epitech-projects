/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_path
*/

#include "print_path.h"
#include "print_path_n.h"
#include <limits.h>

int ftrace_syscall_print_path(
    struct ftrace *self, struct ftrace_process *proc, __kernel_ulong_t address)
{
    return (ftrace_syscall_print_path_n(self, proc, address, PATH_MAX - 1));
}
