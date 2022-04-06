/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_error_message_errno
*/

#pragma once

#include "../../strace.h"

void strace_print_error_message_errno(struct strace *self, const char *format,
    ...);
