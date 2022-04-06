/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Part 2 of print_string
*/

#pragma once

#include "../../strace.h"

typedef struct sspsp2_opts {
    struct strace *self;
    struct strace_process *proc;
    __kernel_ulong_t address;
    char *string;
    char *output_string;
} sspsp2_opts_t;
