/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares syscall_get_number
*/

#pragma once

#include "../../strace.h"

int strace_syscall_get_number(struct strace *self, struct strace_process *proc);
