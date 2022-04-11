/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines cleanup
*/

#include "cleanup.h"
#include "process/detach.h"
#include <signal.h>

void ftrace_cleanup(struct ftrace *self, int fatal_signal)
{
    if (fatal_signal == 0)
        fatal_signal = SIGTERM;
    if (self->has_traced_process && self->traced_process.pid != 0) {
        if (self->traced_process.pid == self->child_pid) {
            kill(self->child_pid, SIGCONT);
            kill(self->child_pid, fatal_signal);
        }
        ftrace_process_detach(self, &self->traced_process);
    }
}
