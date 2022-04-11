/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines entry_buffer_free
*/

#include "entry_buffer_free.h"
#include <stdlib.h>

void ftrace_syscall_entry_buffer_free(void *ptr)
{
    struct ftrace_syscall_entry_buffer *self = ptr;

    self->proc->syscall_entry = NULL;
    free(self);
}
