/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_error_message_errno
*/

#include "errno.h"
#include "../vprint_error_message.h"
#include <errno.h>

void ftrace_print_error_message_errno(struct ftrace *self, const char *format,
    ...)
{
    va_list arguments;

    va_start(arguments, format);
    ftrace_vprint_error_message(self, errno, format, arguments);
    va_end(arguments);
}
