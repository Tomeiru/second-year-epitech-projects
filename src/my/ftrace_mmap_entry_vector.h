/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** Defines a my_vector type
*/

#pragma once

#include "ftrace_mmap_entry_vector_part2.h"

// Destructs the passed vector and the associated data. If you instead want to
// free the vector but gain ownership of self->data, use my_vector_move_buffer
static inline void my_ftrace_mmap_entry_vector_free(
    struct my_ftrace_mmap_entry_vector *self)
{
    if (self == NULL)
        return;
    free(my_ftrace_mmap_entry_vector_move_buffer(self));
}
