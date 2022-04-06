/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares get_syscall_entry
*/

#pragma once

#include "../../strace.h"

const struct strace_syscall_entry *strace_process_get_syscall_entry(
    struct strace_process *self);
