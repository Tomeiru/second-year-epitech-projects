/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** Part 3 of my_vector_type_template
*/

#pragma once

#include "ftrace_symbol_vector_part4.h"

// Append size items from data to self
static inline struct my_ftrace_symbol_vector *
    my_ftrace_symbol_vector_append(struct my_ftrace_symbol_vector *self,
    const struct ftrace_symbol *data, size_t size)
{
    return my_ftrace_symbol_vector_insert(self, data, size, self->size);
}

// Same as append, but for a single item
static inline struct my_ftrace_symbol_vector *
    my_ftrace_symbol_vector_append_single(
    struct my_ftrace_symbol_vector *self, struct ftrace_symbol item)
{
    return my_ftrace_symbol_vector_append(self, &item, 1);
}

// Creates a new vector from the given data (which has size items)
MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_ACCESS((read_only, 1, 2)) static inline
    struct my_ftrace_symbol_vector *my_ftrace_symbol_vector_new_from_data
    (const struct ftrace_symbol *data, size_t size)
{
    struct my_ftrace_symbol_vector *self = my_ftrace_symbol_vector_new();
    if (data)
        my_ftrace_symbol_vector_append(self, data, size);
    return self;
}

// Resizes data to contain size items. If the current size is less than the
// given one, the vector becomes bigger, but has undefined contents after the
// current size. If the current size is greater than the given one, the vector
// is reduced to its first size elements
static inline struct my_ftrace_symbol_vector *
    my_ftrace_symbol_vector_resize(struct my_ftrace_symbol_vector *self,
    size_t size)
{
    if (self == NULL)
        return NULL;
    if (size >= self->allocated_size)
        my_ftrace_symbol_vector_guarantee_can_expand(self, size - self->size);
    self->size = size;
    return self;
}
