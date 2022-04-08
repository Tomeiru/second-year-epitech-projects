/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_string
*/

#include "print_string.h"
#include "print_string_ex.h"

int strace_syscall_print_string(
    struct strace *self, struct strace_process *proc, __kernel_ulong_t address)
{
    return (strace_syscall_print_string_ex(&((sspse_opts_t){self, proc,
        address, -1, STRACE_SYSCALL_PRINT_QUOTE_0_TERM})));
}
