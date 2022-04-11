/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Part 2 of print_quoted_string
*/

#pragma once

#include "../../ftrace.h"

typedef struct sspqsp2_opts {
    struct ftrace *self;
    const char *string;
    size_t size;
    unsigned style;
    char *buffer;
    char *out_string;
    size_t allocation_size;
} sspqsp2_opts_t;
