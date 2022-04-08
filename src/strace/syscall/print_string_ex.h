/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_string_ex
*/

#pragma once

#include "../../strace.h"

typedef struct sspse_opts {
    struct strace *self;
    struct strace_process *proc;
    __kernel_ulong_t address;
    __kernel_ulong_t length;
    unsigned style;
} sspse_opts_t;

int strace_syscall_print_string_ex(sspse_opts_t *o);
