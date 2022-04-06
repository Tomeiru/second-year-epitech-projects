/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares copy_mem_from_pid
*/

#pragma once

#include "../strace.h"

typedef struct scmfp_opts {
    struct strace *self;
    pid_t pid;
    __kernel_ulong_t address;
    size_t length;
    void *output_address;
} scmfp_opts_t;

int strace_copy_mem_from_pid(scmfp_opts_t *o);
