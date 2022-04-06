/*
** EPITECH PROJECT, 2022
** strace
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

void strace_process_drop(struct strace *st, struct strace_process *self)
{
    if (self->pid == 0)
        return;
    strace_process_free_private_data(self);
    st->has_traced_process = false;
    if (st->printing_process == self && self->current_column != 0)
        fprintf(stderr, " <detached ...>\n");
    fflush(stderr);
    if (st->current_process == self)
        strace_set_current_process(st, NULL);
    if (st->printing_process == self)
        st->printing_process = NULL;
    strace_list_remove(&self->event_list);
    memset(self, 0, sizeof(*self));
}
