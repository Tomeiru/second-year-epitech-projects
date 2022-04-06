/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_next_argument
*/

#include "print_next_argument.h"
#include "../printf.h"

void strace_syscall_print_next_argument(struct strace *self)
{
    strace_printf(self, ", ");
}
