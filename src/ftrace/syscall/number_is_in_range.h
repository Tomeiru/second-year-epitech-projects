/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares number_is_in_range
*/

#pragma once

#include <linux/posix_types.h>
#include <stdbool.h>

bool ftrace_syscall_number_is_in_range(__kernel_ulong_t syscall_number);
