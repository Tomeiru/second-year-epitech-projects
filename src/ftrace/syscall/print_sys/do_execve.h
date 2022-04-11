/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares do_execve
*/

#pragma once

#include "../../../ftrace.h"

void ftrace_syscall_print_sys_do_execve(
    struct ftrace *self, struct ftrace_process *proc, unsigned args_index);
