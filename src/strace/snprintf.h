/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares snprintf
*/

#pragma once

#include "../strace.h"

int strace_snprintf(
    struct strace *self, char *buffer, size_t size, const char *format, ...);
