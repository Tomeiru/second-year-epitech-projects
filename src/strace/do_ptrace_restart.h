/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares do_ptrace_restart
*/

#pragma once

#include "../strace.h"

int strace_do_ptrace_restart(struct strace *self, unsigned restart_operation,
    struct strace_process *proc, unsigned signal);
