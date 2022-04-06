/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_end_arguments
*/

#include "print_end_arguments.h"
#include "../printf.h"

void strace_syscall_print_end_arguments(struct strace *self)
{
    strace_printf(self, ")");
}
