/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares get_arguments
*/

#pragma once

#include "../../strace.h"

int strace_syscall_get_arguments(
    struct strace *self, struct strace_process *proc);
