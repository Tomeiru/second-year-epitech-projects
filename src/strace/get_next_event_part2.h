/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Part 2 of get_next_event
*/

#pragma once

#include "../strace.h"
#include "get_next_event_part3.h"
#include "print_error_message.h"
#include "list/is_empty.h"
#include "list/append.h"
#include <sys/wait.h>
#include <assert.h>

static inline void sgne_do_loop_switch_stop(sgne_state_t *s)
{
    switch (s->signal) {
    case SIGSTOP:
    case SIGTSTP:
    case SIGTTIN:
    case SIGTTOU:
        s->event_data->type = STRACE_EVENT_SIGNAL_GROUP_STOPPED;
        break;
    default:
        s->event_data->type = STRACE_EVENT_RESTART;
        break;
    }
}

static inline void sgne_do_loop_switch(sgne_state_t *s)
{    
    switch (s->event) {
    case 0:
        sgne_do_loop_switch_0(s);
        break;
    case PTRACE_EVENT_STOP:
        sgne_do_loop_switch_stop(s);
        break;
    case PTRACE_EVENT_EXEC:
        if (ptrace(PTRACE_GETEVENTMSG, s->pid, NULL, &s->event_data->message) <
            0)
            s->event_data->message = 0;
        s->event_data->type = STRACE_EVENT_BEFORE_EXECVE_STOPPED;
        break;
    case PTRACE_EVENT_EXIT:
        s->event_data->type = STRACE_EVENT_BEFORE_EXIT_STOPPED;
        break;
    default:
        s->event_data->type = STRACE_EVENT_RESTART;
        break;
    }
}

static inline bool sgne_do_loop_proc_non_null_part2(sgne_state_t *s)
{
    if (s->event_data->type == 0)
        strace_print_error_message(s->self, "Tracing event hasn't been "
            "determined for pid %jd, status %0#x", s->pid, s->wait_status);
    if (!strace_list_is_empty(&s->proc->event_list)) {
        s->self->gne_extra_index = s->event_table_position;
        s->self->gne_extra_proc = s->proc;
    } else {
        s->proc->event_data_index = s->event_table_position;
        strace_list_append(&s->self->gne_pending_procs, &s->proc->event_list);
    }
    ++s->event_table_position;
    return (s->self->gne_extra_proc == NULL);
}

static inline bool sgne_do_loop_proc_non_null(sgne_state_t *s)    
{
    strace_event_table_size_check(s->self, s->event_table_position);
    s->event_data = s->self->event_table + s->event_table_position;
    memset(s->event_data, 0, sizeof(*s->event_data));
    s->event_data->wait_status = s->wait_status;
    if (WIFSIGNALED(s->event_data->wait_status))
        s->event_data->type = STRACE_EVENT_SIGNALLED;
    if (WIFEXITED(s->event_data->wait_status))
        s->event_data->type = STRACE_EVENT_EXITED;
    if (s->event_data->type == 0) {
        assert(WIFSTOPPED(s->event_data->wait_status));
        s->signal = WSTOPSIG(s->event_data->wait_status);
        s->event = (unsigned)s->event_data->wait_status >> 16;
        sgne_do_loop_switch(s);
    }
    return (sgne_do_loop_proc_non_null_part2(s));
}
