/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_resume
*/

#pragma once

#include "../../strace.h"

void strace_syscall_print_resume(struct strace *self,
    struct strace_process *proc);
