/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares do_struct_stat
*/

#pragma once

#include "../../ftrace.h"

void ftrace_syscall_do_struct_stat(
    struct ftrace *self, struct ftrace_process *proc, __kernel_ulong_t address);
