/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines entry_buffer_free
*/

#include "entry_buffer_free.h"
#include <stdlib.h>

void strace_syscall_entry_buffer_free(void *ptr)
{
    struct strace_syscall_entry_buffer *self = ptr;

    self->proc->syscall_entry = NULL;
    free(self);
}
