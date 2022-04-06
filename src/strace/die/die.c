/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines die
*/

#include "../die.h"
#include "../cleanup.h"
#include <unistd.h>
#include <stdlib.h>

void strace_die(struct strace *self)
{
    if (self->tracer_pid == getpid()) {
        strace_cleanup(self, 0);
        exit(1);
    }
    _exit(1);
}
