/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares get_syscall_entry
*/

#pragma once

#include "../../ftrace.h"

const struct ftrace_syscall_entry *ftrace_process_get_syscall_entry(
    struct ftrace_process *self);
