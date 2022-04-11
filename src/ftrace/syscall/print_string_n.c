/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_string_n
*/

#include "print_string_n.h"
#include "print_string_ex.h"

int ftrace_syscall_print_string_n(struct ftrace *self,
    struct ftrace_process *proc, __kernel_ulong_t address,
    __kernel_ulong_t length)
{
    return (ftrace_syscall_print_string_ex(&((sspse_opts_t){self, proc,
        address, length, 0})));
}
