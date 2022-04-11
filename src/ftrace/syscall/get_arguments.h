/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares get_arguments
*/

#pragma once

#include "../../ftrace.h"

int ftrace_syscall_get_arguments(
    struct ftrace *self, struct ftrace_process *proc);
