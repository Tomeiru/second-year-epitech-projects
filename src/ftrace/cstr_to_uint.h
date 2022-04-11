/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares cstr_to_uint
*/

#pragma once

#include <stdint.h>

intmax_t ftrace_cstr_to_uint_up_to(const char *str, uintmax_t max_value);

static inline intmax_t ftrace_cstr_to_uintmax(const char *str)
{
    return (ftrace_cstr_to_uint_up_to(str, INTMAX_MAX));
}
