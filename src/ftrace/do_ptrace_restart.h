/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares do_ptrace_restart
*/

#pragma once

#include "../ftrace.h"

int ftrace_do_ptrace_restart(struct ftrace *self, unsigned restart_operation,
    struct ftrace_process *proc, unsigned signal);
