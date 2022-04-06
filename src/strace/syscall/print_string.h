/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_string
*/

#pragma once

#include "../../strace.h"

int strace_syscall_print_string(struct strace *self,
    struct strace_process *proc, __kernel_ulong_t address);
