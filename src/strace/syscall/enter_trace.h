/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares syscall_enter_trace
*/

#pragma once

#include "../../strace.h"

int strace_syscall_enter_trace(struct strace *self,
    struct strace_process *proc);
