/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares do_ptrace_seize
*/

#pragma once

#include "../strace.h"

int strace_do_ptrace_seize(struct strace *self, pid_t pid,
    const char **ptrace_command);
