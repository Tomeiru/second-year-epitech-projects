/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_unavailable
*/

#include "print_unavailable.h"
#include "../printf.h"

void ftrace_syscall_print_unavailable(struct ftrace *self)
{
    ftrace_printf(self, "???");
}
