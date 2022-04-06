/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Part 2 of print_argv
*/

#pragma once

#include "../../strace.h"
#include <stdint.h>

typedef struct sspa_state {
    struct strace *self;
    struct strace_process *proc;
    __kernel_ulong_t address;
    size_t i;
    union {
        uint32_t u32;
        __kernel_ulong_t ul;
        char data[sizeof(__kernel_ulong_t)];
    } c;
    __kernel_ulong_t previous_address;
} sspa_state_t;
