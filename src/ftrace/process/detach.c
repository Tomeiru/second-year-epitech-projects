/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines detach
*/

#include "detach.h"
#include "../print_error_message/errno.h"
#include "../do_ptrace_restart.h"
#include "../print_error_message.h"
#include "drop.h"
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <stdint.h>
#include <errno.h>

static void drop(struct ftrace *st, struct ftrace_process *self)
{
    if (self->flags & STRACE_PROCESS_ATTACHED)
        ftrace_print_error_message(
            st, "Process %ju detached", (uintmax_t)self->pid);
    ftrace_process_drop(st, self);
}

static void wait_loop(struct ftrace *st, struct ftrace_process *self)
{
    unsigned signal;
    int wait_status;
    unsigned event;

    while (true) {
        if (waitpid(self->pid, &wait_status, 0) < 0) {
            if (errno == EINTR)
                continue;
            ftrace_print_error_message_errno(st, "waitpid(%u)", self->pid);
            break;
        }
        if (!WIFSTOPPED(wait_status))
            break;
        signal = WSTOPSIG(wait_status);
        event = (unsigned)wait_status >> 16;
        if (event == PTRACE_EVENT_STOP || signal == SIGTRAP)
            signal = 0;
        ftrace_do_ptrace_restart(st, PTRACE_DETACH, self, signal);
        break;
    }
}

static void spd_part2(struct ftrace *st, struct ftrace_process *self)
{
    int ptrace_error;

    if (syscall(SYS_tkill, self->pid, 0) < 0) {
        if (errno != ESRCH)
            ftrace_print_error_message_errno(st, "tkill(%u,0)", self->pid);
        drop(st, self);
        return;
    }
    ptrace_error = ptrace(PTRACE_INTERRUPT, self->pid, 0, 0);
    if (ptrace_error == 0) {
        wait_loop(st, self);
        return;
    }
    if (errno != ESRCH)
        ftrace_print_error_message_errno(
            st, "ptrace(PTRACE_INTERRUPT,%u)", self->pid);
    drop(st, self);
}

void ftrace_process_detach(struct ftrace *st, struct ftrace_process *self)
{
    int ptrace_error;

    if (!(self->flags & STRACE_PROCESS_ATTACHED)) {
        drop(st, self);
        return;
    }
    ptrace_error = ptrace(PTRACE_DETACH, self->pid, 0, 0);
    if (ptrace_error == 0) {
        drop(st, self);
        return;
    }
    if (errno != ESRCH) {
        ftrace_print_error_message_errno(
            st, "ptrace(PTRACE_DETACH,%u)", self->pid);
        drop(st, self);
        return;
    }
    spd_part2(st, self);
}
