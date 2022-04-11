/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_error_message_and_die
*/

#include "and_die.h"
#include "../vprint_error_message.h"
#include "../die.h"

void ftrace_print_error_message_and_die(
    struct ftrace *self, const char *format, ...)
{
    va_list arguments;

    va_start(arguments, format);
    ftrace_vprint_error_message(self, 0, format, arguments);
    va_end(arguments);
    ftrace_die(self);
}
