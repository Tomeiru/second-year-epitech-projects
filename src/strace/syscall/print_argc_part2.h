/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Part 2 of print_argc
*/

#pragma once

#include "../../strace.h"
#include <stdint.h>

typedef struct sspa_state {
    struct strace *self;
    struct strace_process *proc;
    __kernel_ulong_t address;
    __kernel_ulong_t previous_address;
    size_t i;
    __kernel_ulong_t w;
} sspa_state_t;
