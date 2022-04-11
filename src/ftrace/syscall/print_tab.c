/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_tab
*/

#include "print_tab.h"
#include "../printf.h"

static const char *const COLUMN_SPACES =
    "                                        ";

void ftrace_syscall_print_tab(struct ftrace *self)
{
    if (self->current_process->current_column < 40)
        ftrace_printf(
            self, COLUMN_SPACES + self->current_process->current_column);
}
