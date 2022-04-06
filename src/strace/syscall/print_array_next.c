/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_array_next
*/

#include "print_array_next.h"
#include "../printf.h"

void strace_syscall_print_array_next(struct strace *self)
{
    strace_printf(self, ", ");
}
