/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines arr_sprintf
*/

#pragma once

#include "build_bug_on_non_array.h"
#include "snprintf.h"

#define STRACE_ARR_SPRINTF(self, arr, format, ...) ftrace_snprintf( \
    &((fs_opts_t){self, arr, sizeof(arr) + \
    STRACE_BUILD_BUG_ON_NON_ARRAY(arr), format}), ##__VA_ARGS__)
