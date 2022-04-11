/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Part 2 of print_string_n
*/

#pragma once

#include "../../ftrace.h"

typedef struct sspspe_state {
    struct ftrace *self;
    struct ftrace_process *proc;
    __kernel_ulong_t address;
    __kernel_ulong_t length;
    unsigned style;
    char string[32 + 1];
    char output_string[4 * 32 + 3];
    size_t size;
    int r;
    int printed_all;
} sspse_state_t;
