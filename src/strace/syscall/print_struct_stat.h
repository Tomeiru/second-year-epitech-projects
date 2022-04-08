/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_struct_stat
*/

#pragma once

#include "../../strace.h"
#include <sys/stat.h>

void strace_syscall_print_struct_stat(struct strace *self,
    struct strace_process *proc, const struct stat *stat_buffer);
