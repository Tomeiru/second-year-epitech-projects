/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares syscall_enter_decode
*/

#pragma once

#include "../../ftrace.h"

int ftrace_syscall_enter_decode(struct ftrace *self,
    struct ftrace_process *proc);
