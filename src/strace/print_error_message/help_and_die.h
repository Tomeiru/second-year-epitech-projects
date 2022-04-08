/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_error_message_and_help
*/

#pragma once

#include "../../strace.h"

void strace_print_error_message_help_and_die(
    struct strace *self, const char *format, ...);
