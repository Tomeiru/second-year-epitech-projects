/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_error_message
*/

#include "../print_error_message.h"
#include "../vprint_error_message.h"

void strace_print_error_message(struct strace *self, const char *format, ...)
{
    va_list arguments;

    va_start(arguments, format);
    strace_vprint_error_message(self, 0, format, arguments);
    va_end(arguments);
}
