/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares copy_mem_or_print_address
*/

#pragma once

#include "../../ftrace.h"

typedef struct sscmopa_opts {
    struct ftrace *self;
    struct ftrace_process *proc;
    __kernel_ulong_t address;
    size_t length;
    void *output_address;
} sscmopa_opts_t;

int ftrace_syscall_copy_mem_or_print_address(sscmopa_opts_t *o);
