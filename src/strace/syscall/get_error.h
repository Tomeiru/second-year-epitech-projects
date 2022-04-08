/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares get_error
*/

#pragma once

#include "../../strace.h"

void strace_syscall_get_error(
    struct strace *self, struct strace_process *proc, bool check_errno);
