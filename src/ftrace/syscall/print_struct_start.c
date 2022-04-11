/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_struct_start
*/

#include "print_struct_start.h"
#include "../printf.h"

void ftrace_syscall_print_struct_start(struct ftrace *self)
{
    ftrace_printf(self, "{");
}
