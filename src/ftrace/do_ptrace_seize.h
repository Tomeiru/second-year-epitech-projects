/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares do_ptrace_seize
*/

#pragma once

#include "../ftrace.h"

int ftrace_do_ptrace_seize(
    struct ftrace *self, pid_t pid, const char **ptrace_command);
