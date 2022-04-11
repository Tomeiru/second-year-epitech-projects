/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares copy_str_from_pid
*/

#pragma once

#include "../ftrace.h"

typedef struct scsfp_opts {
    struct ftrace *self;
    pid_t pid;
    __kernel_ulong_t address;
    size_t length;
    void *output_address;
} scsfp_opts_t;

int ftrace_copy_str_from_pid(scsfp_opts_t *o);
