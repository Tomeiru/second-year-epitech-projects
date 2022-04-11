/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_flags
*/

#pragma once

#include "../../ftrace.h"

int ftrace_syscall_print_flags(struct ftrace *self,
    const struct ftrace_enum *enu, uintmax_t flags, const char *default_string);
