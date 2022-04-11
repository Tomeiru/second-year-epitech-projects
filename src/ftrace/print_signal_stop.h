/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_signal_stop
*/

#pragma once

#include "../ftrace.h"

void ftrace_print_signal_stop(struct ftrace *self, struct ftrace_process *proc,
    const siginfo_t *signal_info, unsigned signal);
