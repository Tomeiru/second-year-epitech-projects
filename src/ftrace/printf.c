/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines printf
*/

#include "printf.h"
#include "vprintf.h"
#include <stdarg.h>

void ftrace_printf(struct ftrace *self, const char *format, ...)
{
    va_list arguments;

    va_start(arguments, format);
    ftrace_vprintf(self, format, arguments);
    va_end(arguments);
}
