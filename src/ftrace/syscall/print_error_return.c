/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_error_return
*/

#include "print_error_return.h"
#include "../get_errno_name.h"
#include "../printf.h"
#include <string.h>
#include <stdint.h>

void ftrace_syscall_print_error_return(
    struct ftrace *self, __kernel_ulong_t result, unsigned long error)
{
    const char *error_string = ftrace_get_errno_name(error);

    if (error_string != NULL)
        ftrace_printf(self, "= %jd %s (%s)", (uintmax_t)result, error_string,
            strerror(error));
    else
        ftrace_printf(self, "= %jd (errno %lu)", (uintmax_t)result, error);
}
