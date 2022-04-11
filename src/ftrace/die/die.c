/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines die
*/

#include "../die.h"
#include "../cleanup.h"
#include <unistd.h>
#include <stdlib.h>

void ftrace_die(struct ftrace *self)
{
    if (self->tracer_pid == getpid()) {
        ftrace_cleanup(self, 0);
        exit(1);
    }
    _exit(1);
}
