/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_quoted_c_string
*/

#include "print_quoted_c_string.h"
#include "print_quoted_string.h"
#include "print_more_data_after_this.h"

int strace_syscall_print_quoted_c_string(
    struct strace *self, const char *string, size_t size)
{
    int was_terminated = strace_syscall_print_quoted_string(
        self, string, size, STRACE_SYSCALL_PRINT_QUOTE_0_TERM);

    if (was_terminated != 0)
        strace_syscall_print_more_data_after_this(self);
    return (was_terminated);
}
