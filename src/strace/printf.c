/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines printf
*/

#include "printf.h"
#include "vprintf.h"
#include <stdarg.h>

void strace_printf(struct strace *self, const char *format, ...)
{
    va_list arguments;

    va_start(arguments, format);
    strace_vprintf(self, format, arguments);
    va_end(arguments);
}
