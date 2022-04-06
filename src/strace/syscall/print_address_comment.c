/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_address_comment
*/

#include "print_address_comment.h"
#include "../printf_comment.h"
#include <stdint.h>

void strace_syscall_print_address_comment(struct strace *self,
    __kernel_ulong_t address)
{
    strace_printf_comment(self, "%#jx", (uintmax_t)address);
}
