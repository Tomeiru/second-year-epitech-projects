/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_start_arguments
*/

#pragma once

#include "../../ftrace.h"

void ftrace_syscall_print_start_arguments(
    struct ftrace *self, const char *syscall_name);
