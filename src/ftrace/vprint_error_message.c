/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines vprint_error_message
*/

#include "vprint_error_message.h"
#include <stdio.h>
#include <string.h>

// We flush stderr just in case
void ftrace_vprint_error_message(struct ftrace *self, int errno,
    const char *format, va_list arguments)
{
    fflush(NULL);
    fprintf(stderr, "%s: ", self->program_invocation_name);
    vfprintf(stderr, format, arguments);
    if (errno != 0)
        fprintf(stderr, ": %s\n", strerror(errno));
    else
        fputc('\n', stderr);
    fflush(stderr);
}
