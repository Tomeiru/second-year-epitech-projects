/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares vprint_error_message
*/

#pragma once

#include "../strace.h"
#include <stdarg.h>

void strace_vprint_error_message(
    struct strace *self, int errno, const char *format, va_list arguments);
