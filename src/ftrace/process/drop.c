/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines drop
*/

#include "drop.h"
#include "free_private_data.h"
#include "../set_current_process.h"
#include "../list/remove.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

void ftrace_process_drop(struct ftrace *st, struct ftrace_process *self)
{
    if (self->pid == 0)
        return;
    ftrace_process_free_private_data(self);
    st->has_traced_process = false;
    if (st->printing_process == self && self->current_column != 0)
        fprintf(stderr, " <detached ...>\n");
    fflush(stderr);
    if (st->current_process == self)
        ftrace_set_current_process(st, NULL);
    if (st->printing_process == self)
        st->printing_process = NULL;
    ftrace_list_remove(&self->event_list);
    memset(self, 0, sizeof(*self));
}