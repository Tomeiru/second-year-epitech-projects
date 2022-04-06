/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_event_exit_stopped
*/

#pragma once

#include "../strace.h"

void strace_print_event_exit_stopped(struct strace *self,
    struct strace_process *proc);
