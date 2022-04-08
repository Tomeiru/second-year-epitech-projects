/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines appendf_string
*/

#pragma once

#include "snprintf.h"
#include "build_bug_on_non_array.h"

size_t strace_appendf_string_get_position_difference(struct strace *self,
    char *string, size_t size, char *position);

#define STRACE_APPENDF_STRING(self, str, position, format, ...)  \
    (strace_snprintf(self, position, sizeof(str) + \
    STRACE_BUILD_BUG_ON_NON_ARRAY(str) - \
    strace_appendf_string_get_position_difference((self), (str), sizeof(str), \
    (position)), (format), ##__VA_ARGS__) + position)
