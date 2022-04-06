/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares reallocarray
*/

#pragma once

#include "../strace.h"

void *strace_reallocarray(struct strace *self, void *ptr, size_t num_members,
    size_t size);
