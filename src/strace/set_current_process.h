/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares set_current_process
*/

#pragma once

#include "../strace.h"

void strace_set_current_process(
    struct strace *self, struct strace_process *proc);
