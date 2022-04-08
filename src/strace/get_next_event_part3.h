/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Part 3 of get_next_event
*/

#pragma once

#include "set_current_process.h"
#include "event_table_size_check.h"
#include "process/startup.h"
#include "list/head_remove.h"
#include "list/get_element.h"
#include <string.h>
#include <sys/ptrace.h>
#include <stddef.h>

typedef struct sgne_state {
    struct strace *self;
    int wait_status;
    pid_t pid;
    int wait_errno;
    struct strace_process *proc;
    size_t event_table_position;
    struct strace_event_data *event_data;
    unsigned signal;
    unsigned event;
    bool stopped;
    bool wait_no_hang;
    struct strace_list_item *item;
} sgne_state_t;

static inline struct strace_event_data *sgne_exit(sgne_state_t *s)
{
    if (s->proc->flags & STRACE_PROCESS_BEFORE_FIRST_STOP)
        strace_process_startup(s->self, s->proc);
    strace_set_current_process(s->self, s->proc);
    s->self->current_process = s->proc;
    return (&s->self->event_table[s->proc->event_data_index]);
}

static inline struct strace_event_data *sgne_get_proc(sgne_state_t *s)
{
    s->item = strace_list_head_remove(&s->self->gne_pending_procs);
    if (s->item == NULL) {
        strace_event_table_size_check(s->self, 0);
        memset(s->self->event_table, 0, sizeof(s->self->event_table[0]));
        s->self->event_table[0].type = STRACE_EVENT_NEXT;
        return (&s->self->event_table[0]);
    } else
        s->proc = STRACE_LIST_GET_ELEMENT(s->item, struct strace_process,
            event_list);
    return (sgne_exit(s));
}

static inline void sgne_do_loop_switch_0(sgne_state_t *s)
{
    if (s->signal == SIGTRAP)
        s->event_data->type = STRACE_EVENT_SINGLESTEP_STOPPED;
    else {
        s->stopped = ptrace(PTRACE_GETSIGINFO, s->pid, 0,
            &s->event_data->signal_info) < 0;
        s->event_data->type = s->stopped ? STRACE_EVENT_SIGNAL_GROUP_STOPPED :
            STRACE_EVENT_SIGNAL_DELIVERY_STOPPED;
    }
}
