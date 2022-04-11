/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_enum_value
*/

#pragma once

#include "../../ftrace.h"

int ftrace_syscall_print_enum_value(struct ftrace *self,
    const struct ftrace_enum *enu, uintmax_t value, const char *default_string);
