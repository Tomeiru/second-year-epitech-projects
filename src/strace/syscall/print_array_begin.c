/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_array_begin
*/

#include "print_array_begin.h"
#include "../printf.h"

void strace_syscall_print_array_begin(struct strace *self)
{
    strace_printf(self, "[");
}
