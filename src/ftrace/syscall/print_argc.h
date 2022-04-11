/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_argc
*/

#pragma once

#include "../../ftrace.h"

void ftrace_syscall_print_argc(
    struct ftrace *self, struct ftrace_process *proc, __kernel_ulong_t address);
