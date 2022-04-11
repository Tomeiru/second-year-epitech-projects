/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_address_comment
*/

#include "print_address_comment.h"
#include "../printf_comment.h"
#include <stdint.h>

void ftrace_syscall_print_address_comment(
    struct ftrace *self, __kernel_ulong_t address)
{
    ftrace_printf_comment(self, "%#jx", (uintmax_t)address);
}
