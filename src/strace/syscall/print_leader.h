/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_leader
*/

#pragma once

#include "../../strace.h"

void strace_syscall_print_leader(
    struct strace *self, struct strace_process *proc);
