/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares process_add
*/

#pragma once

#include "../../ftrace.h"

struct ftrace_process *ftrace_process_add(struct ftrace *self, pid_t pid);
