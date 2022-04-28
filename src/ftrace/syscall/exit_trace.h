/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares exit_trace
*/

#pragma once

#include "../../ftrace.h"

int ftrace_syscall_exit_trace(struct ftrace *self, struct ftrace_process *proc,
    int r);
