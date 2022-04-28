/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines init_do_attach
*/

#include "init_do_attach.h"
#include "process/attach.h"
#include "print_error_message/errno.h"
#include "process/drop.h"
#include <errno.h>
#include <stdint.h>

void ftrace_init_do_attach(struct ftrace *self)
{
    if (self->has_traced_process && self->traced_process.pid != 0) {
        if (self->traced_process.flags & STRACE_PROCESS_ATTACHED)
            return;
        if (self->traced_process.pid == self->tracer_pid) {
            errno = EPERM;
            ftrace_print_error_message_errno(self, "attach: pid %jd",
                (intmax_t) self->traced_process.pid);
            ftrace_process_drop(self, &self->traced_process);
            return;
        }
        ftrace_process_attach(self, &self->traced_process);
    }
}
