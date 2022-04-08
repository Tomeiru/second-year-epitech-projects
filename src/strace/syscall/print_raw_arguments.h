/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_raw_arguments
*/

#pragma once

#include "../../strace.h"

int strace_syscall_print_raw_arguments(
    struct strace *self, struct strace_process *proc);
