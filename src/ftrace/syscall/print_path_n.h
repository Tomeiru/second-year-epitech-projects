/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_path_n
*/

#pragma once

#include "../../ftrace.h"

int ftrace_syscall_print_path_n(struct ftrace *self,
    struct ftrace_process *proc, __kernel_ulong_t address, size_t n);
