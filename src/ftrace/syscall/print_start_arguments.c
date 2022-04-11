/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_start_argumeents
*/

#include "print_start_arguments.h"
#include "../printf.h"
#include <stdio.h>

void ftrace_syscall_print_start_arguments(
    struct ftrace *self, const char *syscall_name)
{
    ftrace_printf(self, "%s(", syscall_name);
}
