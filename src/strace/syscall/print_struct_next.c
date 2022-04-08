/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_struct_next
*/

#include "print_struct_next.h"
#include "../printf.h"

void strace_syscall_print_struct_next(struct strace *self)
{
    strace_printf(self, ", ");
}
