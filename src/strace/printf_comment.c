/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines printf_comment
*/

#include "printf_comment.h"
#include "vprintf.h"
#include "syscall/print_comment_begin.h"
#include "syscall/print_comment_end.h"
#include <stddef.h>

void strace_printf_comment(struct strace *self, const char *format, ...)
{
    va_list arguments;
    
    if (format == NULL || *format == '\0')
        return;
    va_start(arguments, format);
    strace_syscall_print_comment_begin(self);
    strace_vprintf(self, format, arguments);
    strace_syscall_print_comment_end(self);
    va_end(arguments);
}
