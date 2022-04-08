/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_error_message_and_die
*/

#include "and_die.h"
#include "../vprint_error_message.h"
#include "../die.h"

void strace_print_error_message_and_die(
    struct strace *self, const char *format, ...)
{
    va_list arguments;

    va_start(arguments, format);
    strace_vprint_error_message(self, 0, format, arguments);
    va_end(arguments);
    strace_die(self);
}
