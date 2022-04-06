/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines snprintf
*/

#include "snprintf.h"
#include "print_error_message/and_die.h"
#include <stdio.h>
#include <stdarg.h>

int strace_snprintf(struct strace *self, char *buffer, size_t size,
    const char *format, ...)
{
    va_list arguments;
    int result;

    va_start(arguments, format);
    result = vsnprintf(buffer, size, format, arguments);
    va_end(arguments);

    if (result < 0 || (unsigned)result >= size)
        strace_print_error_message_and_die(self, "strace_snprintf: got"
            "unexpected return value %d for snprintf(buffer, %zu, \?\?\?\?)",
            result, size);
    return (result);
}
