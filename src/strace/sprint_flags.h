/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares sprint_flags
*/

#pragma once

#include "../strace.h"

typedef struct ssf_opts {
    struct strace *self;
    const char *prefix;
    const struct strace_enum *enu;
    uintmax_t flags;
    char separator;
} ssf_opts_t;

const char *strace_sprint_flags(ssf_opts_t *o);
