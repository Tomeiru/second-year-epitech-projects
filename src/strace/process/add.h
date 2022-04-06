/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares process_add
*/

#pragma once

#include "../../strace.h"

struct strace_process *strace_process_add(struct strace *self, pid_t pid);
