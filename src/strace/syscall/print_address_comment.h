/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_address_comment
*/

#pragma once

#include "../../strace.h"

void strace_syscall_print_address_comment(
    struct strace *self, __kernel_ulong_t address);
