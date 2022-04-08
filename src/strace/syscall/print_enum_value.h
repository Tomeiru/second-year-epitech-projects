/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_enum_value
*/

#pragma once

#include "../../strace.h"

int strace_syscall_print_enum_value(struct strace *self,
    const struct strace_enum *enu, uintmax_t value, const char *default_string);
