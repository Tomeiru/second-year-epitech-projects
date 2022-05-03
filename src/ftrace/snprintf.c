/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines snprintf
*/

#include "snprintf.h"
#include "print_error_message/and_die.h"
#include <stdio.h>
#include <stdarg.h>

int ftrace_snprintf(fs_opts_t *o, ...)
{
    va_list arguments;
    int result;

    va_start(arguments, o);
    result = vsnprintf(o->buffer, o->size, o->format, arguments);
    va_end(arguments);

    if (result < 0 || (unsigned)result >= o->size)
        ftrace_print_error_message_and_die(o->self, "ftrace_snprintf: got"
            "unexpected return value %d for snprintf(buffer, %zu, \?\?\?\?)",
            result, o->size);
    return (result);
}
