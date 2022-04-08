/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_error_return
*/

#include "print_error_return.h"
#include "../get_errno_name.h"
#include "../printf.h"
#include <string.h>
#include <stdint.h>

void strace_syscall_print_error_return(
    struct strace *self, __kernel_ulong_t result, unsigned long error)
{
    const char *error_string = strace_get_errno_name(error);

    if (error_string != NULL)
        strace_printf(self, "= %jd %s (%s)", (uintmax_t)result, error_string,
            strerror(error));
    else
        strace_printf(self, "= %jd (errno %lu)", (uintmax_t)result, error);
}
