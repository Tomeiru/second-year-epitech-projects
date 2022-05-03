/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines get_next_event
*/

#include "get_next_event.h"
#include "get_next_event_part2.h"
#include "print_error_message/errno_and_die.h"
#include "process/get_from_pid.h"
#include <errno.h>

static bool sgne_do_loop_part2(sgne_state_t *s)
{
    s->proc = ftrace_process_get_from_pid(s->self, s->pid);
    if (s->proc != NULL && !sgne_do_loop_proc_non_null(s))
        return (false);
    s->pid = waitpid(-1, &s->wait_status, WNOHANG);
    s->wait_errno = errno;
    s->wait_no_hang = true;
    return (true);
}

static int sgne_do_loop_it(sgne_state_t *s)
{
    if (s->pid < 0) {
        if (s->wait_errno == EINTR || s->wait_no_hang)
            return (1);
        if (!s->self->has_traced_process && s->wait_errno == ECHILD)
            return (2);
        errno = s->wait_errno;
        ftrace_print_error_message_errno_and_die(s->self, "wait4(0)");
    }
    if (s->pid == 0)
        return (1);
    if (!sgne_do_loop_part2(s))
        return (1);
    return (0);
}

static struct ftrace_event_data *sgne_do_loop(sgne_state_t *s)
{
    while (true)
        switch (sgne_do_loop_it(s)) {
        case 1:
            return (sgne_get_proc(s));
        case 2:
            return (NULL);
        }
}

static struct ftrace_event_data *sgne_part2(sgne_state_t *s)
{
    if (ftrace_list_is_empty(&s->self->gne_pending_procs)) {
        if (s->self->gne_extra_proc != NULL) {
            s->proc = s->self->gne_extra_proc;
            s->self->gne_extra_proc = NULL;
            s->proc->event_data_index = s->self->gne_extra_index;
            return (sgne_exit(s));
        }
        s->pid = waitpid(-1, &s->wait_status, __WALL);
        s->wait_errno = errno;
        return (sgne_do_loop(s));
    }
    return (sgne_get_proc(s));
}

// We don't expect ECHILD when we have more
void *ftrace_get_next_event(struct ftrace *self)
{
    sgne_state_t state = {
        .self = self,
        .event_table_position = 0,
    };

    return (sgne_part2(&state));
}
