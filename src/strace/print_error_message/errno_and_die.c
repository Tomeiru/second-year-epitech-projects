/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_error_message_errno_and_die
*/

#include "errno_and_die.h"
#include "../vprint_error_message.h"
#include "../die.h"
#include <errno.h>

void strace_print_error_message_errno_and_die(
    struct strace *self, const char *format, ...)
{
    va_list arguments;

    va_start(arguments, format);
    strace_vprint_error_message(self, errno, format, arguments);
    va_end(arguments);
    strace_die(self);
}
