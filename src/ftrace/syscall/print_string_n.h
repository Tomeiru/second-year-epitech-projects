/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_string_n
*/

#pragma once

#include "../../ftrace.h"

int ftrace_syscall_print_string_n(struct ftrace *self,
    struct ftrace_process *proc, __kernel_ulong_t address,
    __kernel_ulong_t length);
