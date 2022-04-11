/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines process_get_from_pid
*/

#include "get_from_pid.h"
#include <stddef.h>

struct ftrace_process *ftrace_process_get_from_pid(
    struct ftrace *self, pid_t pid)
{
    if (pid <= 0)
        return (NULL);
    if (self->has_traced_process && self->traced_process.pid == pid)
        return (&self->traced_process);
    return (NULL);
}
