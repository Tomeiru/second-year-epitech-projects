/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_exited
*/

#pragma once

#include "../ftrace.h"

void ftrace_print_exited(struct ftrace *self, struct ftrace_process *proc,
    pid_t pid, int wait_status);
