/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares calloc
*/

#pragma once

#include "../strace.h"

void *strace_calloc(struct strace *self, size_t num_members,
    size_t member_size);
