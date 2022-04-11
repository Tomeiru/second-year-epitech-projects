/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_end_arguments
*/

#include "print_end_arguments.h"
#include "../printf.h"

void ftrace_syscall_print_end_arguments(struct ftrace *self)
{
    ftrace_printf(self, ")");
}
