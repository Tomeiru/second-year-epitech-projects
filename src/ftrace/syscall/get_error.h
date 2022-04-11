/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares get_error
*/

#pragma once

#include "../../ftrace.h"

void ftrace_syscall_get_error(
    struct ftrace *self, struct ftrace_process *proc, bool check_errno);
