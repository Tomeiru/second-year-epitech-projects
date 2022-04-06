/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines list_append
*/

#include "append.h"

void strace_list_append(struct strace_list_item *self,
    struct strace_list_item *appended_item)
{
    appended_item->next = self;
    appended_item->prev = self->prev;
    self->prev->next = appended_item;
    self->prev = appended_item;
}
