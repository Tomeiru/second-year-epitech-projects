/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_quoted_string
*/

#pragma once

#include "../../strace.h"

int strace_syscall_print_quoted_string(struct strace *self, const char *string,
    size_t size, unsigned style);
