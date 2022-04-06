/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares stub_entry
*/

#pragma once

#include "../../strace.h"
#include "print_raw_arguments.h"

static const struct strace_syscall_entry STRACE_SYSCALL_STUB_ENTRY = {
    .function = strace_syscall_print_raw_arguments,
    .number = 0,
    .name = "????",
    .num_arguments = 6,
};
