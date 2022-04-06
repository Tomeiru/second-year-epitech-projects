/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_signal_stop
*/

#pragma once

#include "../strace.h"

void strace_print_signal_stop(struct strace *self, struct strace_process *proc,
    const siginfo_t *signal_info, unsigned signal);
