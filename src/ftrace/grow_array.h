/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares grow_array
*/

#pragma once

#include "../ftrace.h"

void *ftrace_grow_array(struct ftrace *self, void *ptr, size_t *num_members,
    size_t member_size);
