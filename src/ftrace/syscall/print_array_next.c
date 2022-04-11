/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_array_next
*/

#include "print_array_next.h"
#include "../printf.h"

void ftrace_syscall_print_array_next(struct ftrace *self)
{
    ftrace_printf(self, ", ");
}
