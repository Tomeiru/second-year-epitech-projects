/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_error_message_errno_and_die
*/

#pragma once

#include "../../ftrace.h"

void ftrace_print_error_message_errno_and_die(
    struct ftrace *self, const char *format, ...);
