/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_error_message_help_and_die
*/

#include "help_and_die.h"
#include "../vprint_error_message.h"
#include "../die.h"
#include <stdio.h>
#include <stddef.h>

void strace_print_error_message_help_and_die(
    struct strace *self, const char *format, ...)
{
    va_list arguments;

    if (format != NULL) {
        va_start(arguments, format);
        strace_vprint_error_message(self, 0, format, arguments);
        va_end(arguments);
    }
    fprintf(stderr, "Try '%s -h' for more information.\n",
        self->program_invocation_name);
    strace_die(self);
}
