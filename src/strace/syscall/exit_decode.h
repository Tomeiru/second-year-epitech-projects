/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares exit_decode
*/

#pragma once

#include "../../strace.h"

int strace_syscall_exit_decode(
    struct strace *self, struct strace_process *proc);
