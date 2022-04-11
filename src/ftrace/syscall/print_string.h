/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_string
*/

#pragma once

#include "../../ftrace.h"

int ftrace_syscall_print_string(
    struct ftrace *self, struct ftrace_process *proc, __kernel_ulong_t address);
