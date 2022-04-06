/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_array_end
*/

#include "print_array_end.h"
#include "../printf.h"

void strace_syscall_print_array_end(struct strace *self)
{
    strace_printf(self, "]");
}
