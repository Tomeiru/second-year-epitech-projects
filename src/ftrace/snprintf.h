/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares snprintf
*/

#pragma once

#include "../ftrace.h"

int ftrace_snprintf(
    struct ftrace *self, char *buffer, size_t size, const char *format, ...);
