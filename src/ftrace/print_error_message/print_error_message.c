/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_error_message
*/

#include "../print_error_message.h"
#include "../vprint_error_message.h"

void ftrace_print_error_message(struct ftrace *self, const char *format, ...)
{
    va_list arguments;

    va_start(arguments, format);
    ftrace_vprint_error_message(self, 0, format, arguments);
    va_end(arguments);
}
