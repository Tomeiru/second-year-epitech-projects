/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines attach
*/

#include "attach.h"
#include "do_post_attach.h"
#include "drop.h"
#include "../do_ptrace_seize.h"
#include "../print_error_message/errno.h"
#include <stdint.h>

void strace_process_attach(struct strace *st, struct strace_process *self)
{
    const char *ptrace_command;

    if (strace_do_ptrace_seize(st, self->pid, &ptrace_command) < 0) {
        strace_print_error_message_errno(st, "attach: ptrace(%s, %jd)",
            ptrace_command, (intmax_t)self->pid);
        strace_process_drop(st, self);
        return;
    }
    strace_process_do_post_attach(st, self, STRACE_PROCESS_GRABBED);
}
