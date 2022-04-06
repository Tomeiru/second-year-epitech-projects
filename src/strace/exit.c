/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines exit
*/

#include "exit.h"
#include "cleanup.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void strace_exit(struct strace *self)
{
    sigset_t signal_mask;

    strace_cleanup(self, 0);
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
