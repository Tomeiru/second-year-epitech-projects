/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares do_trace_syscall
*/

#pragma once

#include "../strace.h"

int strace_do_trace_syscall(struct strace *self, struct strace_process *proc);
