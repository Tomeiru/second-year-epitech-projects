/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares copy_struct_stat_from_pid
*/

#pragma once

#include "../ftrace.h"
#include <sys/stat.h>

bool ftrace_copy_struct_stat_from_pid(struct ftrace *self,
    struct ftrace_process *proc, __kernel_ulong_t address,
    struct stat *stat_bufferE);
