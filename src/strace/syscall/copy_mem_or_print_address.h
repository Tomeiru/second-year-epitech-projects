/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares copy_mem_or_print_address
*/

#pragma once

#include "../../strace.h"

typedef struct sscmopa_opts {
    struct strace *self;
    struct strace_process *proc;
    __kernel_ulong_t address;
    size_t length;
    void *output_address;
} sscmopa_opts_t;

int strace_syscall_copy_mem_or_print_address(sscmopa_opts_t *o);
