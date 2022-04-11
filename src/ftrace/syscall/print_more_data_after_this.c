/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_more_data_after_this
*/

#include "print_more_data_after_this.h"
#include "../printf.h"

void ftrace_syscall_print_more_data_after_this(struct ftrace *self)
{
    ftrace_printf(self, "...");
}
