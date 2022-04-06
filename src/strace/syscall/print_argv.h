/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_argv
*/

#pragma once

#include "../../strace.h"

void strace_syscall_print_argv(struct strace *self, struct strace_process *proc,
    __kernel_ulong_t address);
