/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares reallocarray
*/

#pragma once

#include "../ftrace.h"

void *ftrace_reallocarray(
    struct ftrace *self, void *ptr, size_t num_members, size_t size);
