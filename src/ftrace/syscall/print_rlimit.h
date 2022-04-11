/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_rlimit
*/

#pragma once

#include "../../ftrace.h"

void ftrace_syscall_print_rlimit(struct ftrace *self,
    struct ftrace_process *proc, __syscall_ulong_t address);
