/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_tab
*/

#include "print_tab.h"
#include "../printf.h"

static const char *const COLUMN_SPACES =
    "                                        ";

void strace_syscall_print_tab(struct strace *self)
{
    if (self->current_process->current_column < 40)
        strace_printf(
            self, COLUMN_SPACES + self->current_process->current_column);
}
