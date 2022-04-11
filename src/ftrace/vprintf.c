/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines vprintf
*/

#include "vprintf.h"
#include <stdio.h>

void ftrace_vprintf(struct ftrace *self, const char *format, va_list arguments)
{
    int result;

    if (self->current_process != NULL) {
        result = vfprintf(stderr, format, arguments);
        if (result >= 0)
            self->current_process->current_column += result;
    }
}
