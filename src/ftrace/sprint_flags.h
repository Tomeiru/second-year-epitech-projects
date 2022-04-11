/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares sprint_flags
*/

#pragma once

#include "../ftrace.h"

typedef struct ssf_opts {
    struct ftrace *self;
    const char *prefix;
    const struct ftrace_enum *enu;
    uintmax_t flags;
    char separator;
} ssf_opts_t;

const char *ftrace_sprint_flags(ssf_opts_t *o);
