/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_rlimit
*/

#pragma once

#include "../../strace.h"

void strace_syscall_print_rlimit(struct strace *self,
    struct strace_process *proc, __syscall_ulong_t address);
