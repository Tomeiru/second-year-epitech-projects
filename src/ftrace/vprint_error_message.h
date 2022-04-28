/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares vprint_error_message
*/

#pragma once

#include "../ftrace.h"
#include <stdarg.h>

void ftrace_vprint_error_message(struct ftrace *self, int errno,
    const char *format, va_list arguments);
