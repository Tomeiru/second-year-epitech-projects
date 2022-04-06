/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_more_data_after_this
*/

#include "print_more_data_after_this.h"
#include "../printf.h"

void strace_syscall_print_more_data_after_this(struct strace *self)
{
    strace_printf(self, "...");
}
