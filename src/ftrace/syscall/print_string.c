/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_string
*/

#include "print_string.h"
#include "print_string_ex.h"

int ftrace_syscall_print_string(
    struct ftrace *self, struct ftrace_process *proc, __kernel_ulong_t address)
{
    return (ftrace_syscall_print_string_ex(&((sspse_opts_t){self, proc,
        address, -1, STRACE_SYSCALL_PRINT_QUOTE_0_TERM})));
}
