/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_signalled
*/

#pragma once

#include "../strace.h"

void strace_print_signalled(struct strace *self, struct strace_process *proc,
    pid_t pid, int wait_status);
