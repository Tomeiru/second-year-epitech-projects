/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines exit
*/

#include "exit.h"
#include "cleanup.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void ftrace_exit(struct ftrace *self)
{
    sigset_t signal_mask;

    ftrace_cleanup(self, 0);
    fflush(NULL);
    if (self->exit_status > 0xFF) {
        self->exit_status &= 0xFF;
        signal(self->exit_status, SIG_DFL);
        raise(self->exit_status);
        sigemptyset(&signal_mask);
        sigaddset(&signal_mask, self->exit_status);
        sigprocmask(SIG_UNBLOCK, &signal_mask, NULL);
        self->exit_status += 0x80;
    }
    exit(self->exit_status);
}
