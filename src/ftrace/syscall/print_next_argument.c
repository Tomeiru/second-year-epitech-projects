/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_next_argument
*/

#include "print_next_argument.h"
#include "../printf.h"

void ftrace_syscall_print_next_argument(struct ftrace *self)
{
    ftrace_printf(self, ", ");
}
