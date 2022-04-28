/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares process_get_from_pid
*/

#pragma once

#include "../../ftrace.h"

struct ftrace_process *ftrace_process_get_from_pid(struct ftrace *self,
    pid_t pid);
