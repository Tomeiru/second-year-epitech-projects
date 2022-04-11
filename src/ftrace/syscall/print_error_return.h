/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_error_return
*/

#pragma once

#include "../../ftrace.h"

void ftrace_syscall_print_error_return(
    struct ftrace *self, __kernel_ulong_t result, unsigned long error);
