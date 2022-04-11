/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares stub_entry
*/

#pragma once

#include "../../ftrace.h"
#include "print_raw_arguments.h"

static const struct ftrace_syscall_entry STRACE_SYSCALL_STUB_ENTRY = {
    .function = ftrace_syscall_print_raw_arguments,
    .number = 0,
    .name = "????",
    .num_arguments = 6,
};
