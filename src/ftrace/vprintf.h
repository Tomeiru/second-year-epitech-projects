/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares vprintf
*/

#pragma once

#include "../ftrace.h"
#include <stdarg.h>

void ftrace_vprintf(struct ftrace *self, const char *format, va_list arguments);
