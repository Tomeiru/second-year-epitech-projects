/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares copy_struct_stat_from_pid
*/

#pragma once

#include "../strace.h"
#include <sys/stat.h>

bool strace_copy_struct_stat_from_pid(struct strace *self,
    struct strace_process *proc, __kernel_ulong_t address,
    struct stat *stat_bufferE);
