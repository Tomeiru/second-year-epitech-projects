/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_struct_stat
*/

#pragma once

#include "../../ftrace.h"
#include <sys/stat.h>

void ftrace_syscall_print_struct_stat(struct ftrace *self,
    struct ftrace_process *proc, const struct stat *stat_buffer);
