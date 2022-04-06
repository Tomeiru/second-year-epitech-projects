/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares exit_finish
*/

#pragma once

#include "../../strace.h"

void strace_syscall_exit_finish(struct strace *self,
    struct strace_process *proc);
