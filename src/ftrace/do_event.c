/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines do_event
*/

#include "do_event.h"
#include "do_event_part2.h"
#include "do_trace_syscall.h"
#include "do_trace_call.h"
#include "do_trace_ret.h"
#include "print_error_message.h"
#include "print_signal_stop.h"
#include "print_signalled.h"
#include "print_exited.h"
#include "print_event_exit_stopped.h"
#include "do_ptrace_restart.h"
#include "process/drop.h"
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <assert.h>
#include <stdint.h>
#include <stddef.h>

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

static bool sde_part4(sde_state_t *s)
{
    if (s->event_type == STRACE_EVENT_BEFORE_EXECVE_STOPPED) {
        s->self->current_process->flags &= ~STRACE_PROCESS_CHECK_EXEC_SUCCESS;
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
    }
    return (sde_part5(s));
}

static bool sde_part3(sde_state_t *s)
{
    if (s->event_type == STRACE_EVENT_SIGNAL_GROUP_STOPPED) {
        ftrace_print_signal_stop(s->self, s->self->current_process,
            s->restart_signal);
        s->restart_operation = PTRACE_LISTEN;
        s->restart_signal = 0;
    }
    if (s->event_type == STRACE_EVENT_EXITED) {
        ftrace_print_exited(s->self, s->self->current_process,
            s->self->current_process->pid, s->wait_status);
        ftrace_process_drop(s->self, s->self->current_process);
        return (true);
    }
    return (sde_part4(s));
}

static bool sde_part2(sde_state_t *s)
{
    if (s->event_type == STRACE_EVENT_BREAK_MAIN_LOOP)
        return (false);
    if (s->event_type == STRACE_EVENT_NEXT)
        return (true);
    if (s->event_type == STRACE_EVENT_SINGLESTEP_STOPPED &&
        (ftrace_do_trace_syscall(s->self, s->self->current_process) < 0 ||
        ftrace_do_trace_call(s->self, s->self->current_process) < 0 ||
        ftrace_do_trace_ret(s->self, s->self->current_process) < 0))
        return (true);
    if (s->event_type == STRACE_EVENT_SIGNAL_DELIVERY_STOPPED) {
        s->restart_signal = WSTOPSIG(s->wait_status);
        ftrace_print_signal_stop(s->self, s->self->current_process,
            s->restart_signal);
    }
    if (s->event_type == STRACE_EVENT_SIGNALLED) {
        ftrace_print_signalled(s->self, s->self->current_process,
            s->self->current_process->pid, s->wait_status);
        ftrace_process_drop(s->self, s->self->current_process);
        return (true);
    }
    return (sde_part3(s));
}

bool ftrace_do_event(struct ftrace *self,
    const struct ftrace_event_data *event_data)
{
    sde_state_t state = {
        .self = self,
        .event_data = event_data,
        .event_type = event_data != NULL ? event_data->type :
            STRACE_EVENT_BREAK_MAIN_LOOP,
        .restart_signal = 0,
        .wait_status = event_data != NULL ? event_data->wait_status : 0,
        .restart_operation = PTRACE_SINGLESTEP,
    };

    return (sde_part2(&state));
}
