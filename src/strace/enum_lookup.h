/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares enum_lookup
*/

#pragma once

#include "../strace.h"

const char *strace_enum_lookup(const struct strace_enum *enu, uintmax_t value);
