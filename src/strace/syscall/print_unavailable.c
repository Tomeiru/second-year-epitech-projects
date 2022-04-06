/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_unavailable
*/

#include "print_unavailable.h"
#include "../printf.h"

void strace_syscall_print_unavailable(struct strace *self)
{
    strace_printf(self, "???");
}
