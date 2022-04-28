/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares syscall_enter_trace
*/

#pragma once

#include "../../ftrace.h"

int ftrace_syscall_enter_trace(struct ftrace *self,
    struct ftrace_process *proc);
