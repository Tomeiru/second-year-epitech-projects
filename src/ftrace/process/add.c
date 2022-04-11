/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines process_add
*/

#include "add.h"
#include "../print_error_message/and_die.h"
#include <string.h>

struct ftrace_process *ftrace_process_add(struct ftrace *self, pid_t pid)
{
    if (self->has_traced_process)
        ftrace_print_error_message_and_die(
            self, "TODO: support tracing multiple processes at once");
    memset(&self->traced_process, 0, sizeof(self->traced_process));
    self->traced_process.pid = pid;
    self->has_traced_process = true;
    return (&self->traced_process);
}
