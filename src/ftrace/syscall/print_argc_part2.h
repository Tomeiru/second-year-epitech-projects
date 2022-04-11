/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Part 2 of print_argc
*/

#pragma once

#include "../../ftrace.h"
#include <stdint.h>

typedef struct sspa_state {
    struct ftrace *self;
    struct ftrace_process *proc;
    __kernel_ulong_t address;
    __kernel_ulong_t previous_address;
    size_t i;
    __kernel_ulong_t w;
} sspa_state_t;
