/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_flags
*/

#pragma once

#include "../../strace.h"

int strace_syscall_print_flags(struct strace *self,
    const struct strace_enum *enu, uintmax_t flags, const char *default_string);
