/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares do_struct_stat
*/

#pragma once

#include "../../strace.h"

void strace_syscall_do_struct_stat(
    struct strace *self, struct strace_process *proc, __kernel_ulong_t address);
