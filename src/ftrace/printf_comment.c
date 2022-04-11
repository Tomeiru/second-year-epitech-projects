/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines printf_comment
*/

#include "printf_comment.h"
#include "vprintf.h"
#include "syscall/print_comment_begin.h"
#include "syscall/print_comment_end.h"
#include <stddef.h>

void ftrace_printf_comment(struct ftrace *self, const char *format, ...)
{
    va_list arguments;

    if (format == NULL || *format == '\0')
        return;
    va_start(arguments, format);
    ftrace_syscall_print_comment_begin(self);
    ftrace_vprintf(self, format, arguments);
    ftrace_syscall_print_comment_end(self);
    va_end(arguments);
}
