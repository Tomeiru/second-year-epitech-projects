/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_struct_next
*/

#include "print_struct_next.h"
#include "../printf.h"

void ftrace_syscall_print_struct_next(struct ftrace *self)
{
    ftrace_printf(self, ", ");
}
