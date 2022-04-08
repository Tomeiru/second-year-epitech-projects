/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_path
*/

#pragma once

#include "../../strace.h"

int strace_syscall_print_path(
    struct strace *self, struct strace_process *proc, __kernel_ulong_t address);
