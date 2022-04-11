/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_array_begin
*/

#include "print_array_begin.h"
#include "../printf.h"

void ftrace_syscall_print_array_begin(struct ftrace *self)
{
    ftrace_printf(self, "[");
}
