/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_path
*/

#pragma once

#include "../../ftrace.h"

int ftrace_syscall_print_path(
    struct ftrace *self, struct ftrace_process *proc, __kernel_ulong_t address);
