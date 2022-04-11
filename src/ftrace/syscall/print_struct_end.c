/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_struct_end
*/

#include "print_struct_end.h"
#include "../printf.h"

void ftrace_syscall_print_struct_end(struct ftrace *self)
{
    ftrace_printf(self, "}");
}
