/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Defines guarantee_can_expand
*/

#include "my/internal/my_string.h"
#include "my/stdlib.h"
#include "my/cpp-like/algorithm.h"

// We allocate some extra bytes to reduce the amount of calls to realloc when
// frequently increasing the size of self
static const size_t EXTRA_ALLOCATED_SPACE = 16;

struct my_string *my_string_guarantee_can_expand(struct my_string *self,
    size_t length)
{
    if (self->length + length >= self->allocated_size) {
        self->allocated_size =
            MY_MAX(self->length + length + 1 + EXTRA_ALLOCATED_SPACE,
                self->length * 3 / 2);
        self->string = (char *)my_xrealloc(self->string, self->allocated_size);
    }
    return self;
}
