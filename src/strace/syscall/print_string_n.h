/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_string_n
*/

#pragma once

#include "../../strace.h"

int strace_syscall_print_string_n(struct strace *self,
    struct strace_process *proc, __kernel_ulong_t address,
    __kernel_ulong_t length);
