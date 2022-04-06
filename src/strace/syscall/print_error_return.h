/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_error_return
*/

#pragma once

#include "../../strace.h"

void strace_syscall_print_error_return(struct strace *self,
    __kernel_ulong_t result, unsigned long error);
