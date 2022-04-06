/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares do_execve
*/

#pragma once

#include "../../../strace.h"

void strace_syscall_print_sys_do_execve(struct strace *self,
    struct strace_process *proc, unsigned args_index);
