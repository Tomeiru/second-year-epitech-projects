/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_string_ex
*/

#pragma once

#include "../../ftrace.h"

typedef struct sspse_opts {
    struct ftrace *self;
    struct ftrace_process *proc;
    __kernel_ulong_t address;
    __kernel_ulong_t length;
    unsigned style;
} sspse_opts_t;

int ftrace_syscall_print_string_ex(sspse_opts_t *o);
