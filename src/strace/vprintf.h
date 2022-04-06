/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares vprintf
*/

#pragma once

#include "../strace.h"
#include <stdarg.h>

void strace_vprintf(struct strace *self, const char *format, va_list arguments);
