/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Part 2 of do_event
*/

#pragma once

#include "../ftrace.h"
#include "print_event_exit_stopped.h"
#include "do_ptrace_restart.h"
#include "print_error_message.h"
#include "do_trace_syscall.h"

typedef struct sde_state {
    struct ftrace *self;
    const struct ftrace_event_data *event_data;
    enum ftrace_event_type event_type;
    unsigned restart_signal;
    int wait_status;
    unsigned restart_operation;
    int r;
} sde_state_t;

static bool sde_part5(sde_state_t *s)
{
    if (s->event_type == STRACE_EVENT_BEFORE_EXIT_STOPPED)
        ftrace_print_event_exit_stopped(s->self, s->self->current_process);
    if (ftrace_do_ptrace_restart(s->self, s->restart_operation,
        s->self->current_process, s->restart_signal) < 0) {
        s->self->exit_status = 1;
        return (false);
    }
    return (true);
}

static bool sde_part4_2(sde_state_t *s)
{
    if (!(s->self->current_process->flags & STRACE_PROCESS_IN_SYSCALL)) {
        ftrace_print_error_message(s->self, "Stay PTRACE_EVENT_EXEC from "
            "pid %jd, trying to recover...",
            (intmax_t)s->self->current_process->pid);
        s->self->current_process->flags |= STRACE_PROCESS_RECOVERING;
        s->r = ftrace_do_trace_syscall(s->self, s->self->current_process);
        s->self->current_process->flags &= ~STRACE_PROCESS_RECOVERING;
        if (s->r < 0)
            return (true);
    }
    return (false);
}

static bool sde_part4(sde_state_t *s)
{
    if (s->event_type == STRACE_EVENT_BEFORE_EXECVE_STOPPED) {
        s->self->current_process->flags &= ~STRACE_PROCESS_CHECK_EXEC_SUCCESS;
        if (sde_part4_2(s))
            return (true);
    }
    return (sde_part5(s));
}
