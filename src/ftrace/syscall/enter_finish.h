/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares enter_finish
*/

#pragma once

#include "../../ftrace.h"

void ftrace_syscall_enter_finish(
    struct ftrace *self, struct ftrace_process *proc, int r);
