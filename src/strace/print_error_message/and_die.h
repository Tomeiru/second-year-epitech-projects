/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_error_message_and_die
*/

#pragma once

#include "../../strace.h"

void strace_print_error_message_and_die(struct strace *self,
    const char *format, ...);
