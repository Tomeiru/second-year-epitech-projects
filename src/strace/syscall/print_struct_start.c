/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_struct_start
*/

#include "print_struct_start.h"
#include "../printf.h"

void strace_syscall_print_struct_start(struct strace *self)
{
    strace_printf(self, "{");
}
