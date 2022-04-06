/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_line_ended
*/

#include "print_line_ended.h"
#include <stdio.h>

void strace_syscall_print_line_ended(struct strace *self)
{
    if (self->current_process != NULL) {
        self->current_process->current_column = 0;
        fflush(stderr);
    }
    if (self->printing_process != NULL) {
        self->printing_process->current_column = 0;
        self->printing_process = NULL;
    }
}
