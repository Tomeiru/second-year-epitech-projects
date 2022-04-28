/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares exit_decode
*/

#pragma once

#include "../../ftrace.h"

int ftrace_syscall_exit_decode(struct ftrace *self,
    struct ftrace_process *proc);
