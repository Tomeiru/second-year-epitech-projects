/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_start_arguments
*/

#pragma once

#include "../../strace.h"

void strace_syscall_print_start_arguments(struct strace *self,
    const char *syscall_name);
