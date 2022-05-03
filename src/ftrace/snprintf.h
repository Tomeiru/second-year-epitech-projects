/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares snprintf
*/

#pragma once

#include "../ftrace.h"

typedef struct fs_opts {
    struct ftrace *self;
    char *buffer;
    size_t size;
    const char *format;
} fs_opts_t;

int ftrace_snprintf(fs_opts_t *o, ...);
