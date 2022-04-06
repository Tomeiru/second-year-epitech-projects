/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines process_add
*/

#include "add.h"
#include "../print_error_message/and_die.h"
#include <string.h>

struct strace_process *strace_process_add(struct strace *self, pid_t pid)
{
    if (self->has_traced_process)
        strace_print_error_message_and_die(self,
            "TODO: support tracing multiple processes at once");
    memset(&self->traced_process, 0, sizeof(self->traced_process));
    self->traced_process.pid = pid;
    self->has_traced_process = true;
    return (&self->traced_process);
}
