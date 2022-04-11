/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_array_end
*/

#include "print_array_end.h"
#include "../printf.h"

void ftrace_syscall_print_array_end(struct ftrace *self)
{
    ftrace_printf(self, "]");
}
