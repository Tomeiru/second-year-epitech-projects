/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_struct_end
*/

#include "print_struct_end.h"
#include "../printf.h"

void strace_syscall_print_struct_end(struct strace *self)
{
    strace_printf(self, "}");
}
