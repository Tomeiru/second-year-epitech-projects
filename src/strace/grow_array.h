/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares grow_array
*/

#pragma once

#include "../strace.h"

void *strace_grow_array(
    struct strace *self, void *ptr, size_t *num_members, size_t member_size);
