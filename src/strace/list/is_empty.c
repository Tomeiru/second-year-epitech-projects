/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines list_is_empty
*/

#include "is_empty.h"
#include <stddef.h>

bool strace_list_is_empty(struct strace_list_item *self)
{
    return ((self->next == self && self->prev == self) ||
        (self->next == NULL && self->prev == NULL));
}
