/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** Part 4 of my_vector_type_template
*/

#pragma once

#include "my/cpp-like/algorithm.h"
#include "my/stdlib.h"
#include "my/features.h"
#include "../ftrace/symbol.h"
#include <string.h>
#include <stddef.h>

struct my_ftrace_symbol_vector {
    size_t size;
    size_t allocated_size;
    struct ftrace_symbol *data;
};

// Guarantees that there will be at least self->length + length bytes available
// in the vector
static inline struct my_ftrace_symbol_vector *
    my_ftrace_symbol_vector_guarantee_can_expand(
    struct my_ftrace_symbol_vector *self, size_t size)
{
    size_t current_allocated_size = self->allocated_size;

    if (self->size + size >= current_allocated_size) {
        self->allocated_size = MY_MAX(self->size + size + 16,
            self->size * 3 / 2);
        self->data = (struct ftrace_symbol *)my_xrealloc(self->data,
            self->allocated_size * sizeof(*self->data));
    }
    return self;
}

// Creates a new, empty, vector
MY_ATTR_WARN_UNUSED_RESULT static inline struct my_ftrace_symbol_vector *
    my_ftrace_symbol_vector_new(void)
{
    struct my_ftrace_symbol_vector *self =
        (struct my_ftrace_symbol_vector *)my_xmalloc(sizeof(*self));

    self->size = 0;
    self->allocated_size = 0;
    self->data = NULL;
    return my_ftrace_symbol_vector_guarantee_can_expand(self, 1);
}

// Inserts size bytes from data to self at position. data may not part of self
// (i.e. directly located within self->data)
static inline struct my_ftrace_symbol_vector *
    my_ftrace_symbol_vector_insert(struct my_ftrace_symbol_vector *self,
    const struct ftrace_symbol *data, size_t size, size_t position)
{
    if (self == NULL || data == NULL || size == 0 || (position > self->size))
        return self;
    my_ftrace_symbol_vector_guarantee_can_expand(self, size);
    memmove(self->data + position + size, self->data + position,
        (self->size - position) * sizeof(*self->data));
    memcpy(self->data + position, data, size * sizeof(*self->data));
    self->size += size;
    return self;
}

// Same as insert, but for a single item
static inline struct my_ftrace_symbol_vector *
    my_ftrace_symbol_vector_insert_single(
    struct my_ftrace_symbol_vector *self,
    struct ftrace_symbol item,
    size_t position)
{
    return my_ftrace_symbol_vector_insert(self, &item, 1, position);
}

