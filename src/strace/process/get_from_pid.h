/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares process_get_from_pid
*/

#pragma once

#include "../../strace.h"

struct strace_process *strace_process_get_from_pid(
    struct strace *self, pid_t pid);
