/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares syscall_enter_decode
*/

#pragma once

#include "../../strace.h"

int strace_syscall_enter_decode(struct strace *self,
    struct strace_process *proc);
