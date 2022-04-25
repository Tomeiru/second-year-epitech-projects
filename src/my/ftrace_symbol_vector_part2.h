/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** Part 2 of my_vector_type_template
*/

#pragma once

#include "ftrace_symbol_vector_part3.h"

// Removes all the items in the vector, as if by using my_vector_resize(self, 0)
static inline struct my_ftrace_symbol_vector *
    my_ftrace_symbol_vector_clear(struct my_ftrace_symbol_vector *self)
{
    return my_ftrace_symbol_vector_resize(self, 0);
}

// Copies source into self
static inline struct my_ftrace_symbol_vector *
    my_ftrace_symbol_vector_assign(struct my_ftrace_symbol_vector *self,
    const struct my_ftrace_symbol_vector *source)
{
    if (self == NULL)
        return NULL;
    my_ftrace_symbol_vector_resize(self, source->size);
    memcpy(self->data, source->data, self->size * sizeof(*self->data));
    return self;
}

// Remove size items starting at position
static inline struct my_ftrace_symbol_vector *
    my_ftrace_symbol_vector_erase(struct my_ftrace_symbol_vector *self,
    size_t position, size_t size)
{
    if (self == NULL || position > self->size || (position + size) > self->size)
        return self;
    memmove(self->data + position, self->data + position + size,
        (self->size - (position + size)) * sizeof(*self->data));
    self->size -= size;
    return self;
}

// Destructs the passed vector but returns the underlying buffer
static inline struct ftrace_symbol *
    my_ftrace_symbol_vector_move_buffer(
    struct my_ftrace_symbol_vector *self)
{
    struct ftrace_symbol *result = self->data;

    free(self);
    return result;
}
