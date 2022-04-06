/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares copy_str_from_pid
*/

#pragma once

#include "../strace.h"

typedef struct scsfp_opts {
    struct strace *self;
    pid_t pid;
    __kernel_ulong_t address;
    size_t length;
    void *output_address;
} scsfp_opts_t;

int strace_copy_str_from_pid(scsfp_opts_t *o);
