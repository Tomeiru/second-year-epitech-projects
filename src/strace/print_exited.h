/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_exited
*/

#pragma once

#include "../strace.h"

void strace_print_exited(struct strace *self, struct strace_process *proc,
    pid_t pid, int wait_status);
