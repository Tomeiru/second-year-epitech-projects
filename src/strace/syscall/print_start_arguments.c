/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_start_argumeents
*/

#include "print_start_arguments.h"
#include "../printf.h"
#include <stdio.h>

void strace_syscall_print_start_arguments(struct strace *self,
    const char *syscall_name)
{
    strace_printf(self, "%s(", syscall_name);
}
