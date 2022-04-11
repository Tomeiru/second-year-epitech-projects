/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines event_table_size_check
*/

#include "event_table_size_check.h"
#include "grow_array.h"

void ftrace_event_table_size_check(struct ftrace *self, size_t size)
{
    if (size >= self->event_table_size)
        self->event_table = ftrace_grow_array(self, self->event_table,
            &self->event_table_size, sizeof(self->event_table[0]));
}
