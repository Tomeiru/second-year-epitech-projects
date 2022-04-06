/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares exit_trace
*/

#pragma once

#include "../../strace.h"

int strace_syscall_exit_trace(struct strace *self, struct strace_process *proc,
    int r);
