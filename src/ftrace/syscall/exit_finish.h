/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares exit_finish
*/

#pragma once

#include "../../ftrace.h"

void ftrace_syscall_exit_finish(struct ftrace *self,
    struct ftrace_process *proc);
