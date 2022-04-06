/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines process_get_from_pid
*/

#include "get_from_pid.h"
#include <stddef.h>

struct strace_process *strace_process_get_from_pid(struct strace *self,
    pid_t pid)
{
    if (pid <= 0)
        return (NULL);
    if (self->has_traced_process && self->traced_process.pid == pid)
        return (&self->traced_process);
    return (NULL);
}
