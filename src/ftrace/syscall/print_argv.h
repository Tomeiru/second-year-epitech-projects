/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_argv
*/

#pragma once

#include "../../ftrace.h"

void ftrace_syscall_print_argv(
    struct ftrace *self, struct ftrace_process *proc, __kernel_ulong_t address);
