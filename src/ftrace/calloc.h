/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares calloc
*/

#pragma once

#include "../ftrace.h"

void *ftrace_calloc(struct ftrace *self, size_t num_members,
    size_t member_size);
