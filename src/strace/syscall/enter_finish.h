/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares enter_finish
*/

#pragma once

#include "../../strace.h"

void strace_syscall_enter_finish(struct strace *self,
    struct strace_process *proc, int r);
