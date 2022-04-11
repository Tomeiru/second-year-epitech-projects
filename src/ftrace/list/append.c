/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines list_append
*/

#include "append.h"

void ftrace_list_append(
    struct ftrace_list_item *self, struct ftrace_list_item *appended_item)
{
    appended_item->next = self;
    appended_item->prev = self->prev;
    self->prev->next = appended_item;
    self->prev = appended_item;
}
