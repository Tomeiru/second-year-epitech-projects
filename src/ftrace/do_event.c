/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines do_event
*/

#include "do_event.h"
#include "do_event_part2.h"
#include "print_signal_stop.h"
#include "print_exited.h"
#include "do_trace_call.h"
#include "do_trace_ret.h"
#include "print_signalled.h"
#include "process/drop.h"
#include <sys/ptrace.h>

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

static bool sde_part2_2(sde_state_t *s)
{
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
    return (sde_part2_2(s));
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
