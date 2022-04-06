/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines get_next_event
*/

#include "get_next_event.h"
#include "print_error_message/errno_and_die.h"
#include "process/get_from_pid.h"
#include "get_next_event_part2.h"
#include "event_table_size_check.h"
#include "print_error_message.h"
#include "list/is_empty.h"
#include "list/append.h"
#include "list/head_remove.h"
#include "list/get_element.h"
#include "process/startup.h"
#include "set_current_process.h"
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stddef.h>

static struct strace_event_data *sgne_exit(sgne_state_t *s)
{
    if (s->proc->flags & STRACE_PROCESS_BEFORE_FIRST_STOP)
        strace_process_startup(s->self, s->proc);
    strace_set_current_process(s->self, s->proc);
    s->self->current_process = s->proc;
    return (&s->self->event_table[s->proc->event_data_index]);
}

static struct strace_event_data *sgne_get_proc(sgne_state_t *s)
{
    s->item = strace_list_head_remove(&s->self->gne_pending_procs);
    if (s->item == NULL) {
        strace_event_table_size_check(s->self, 0);
        memset(s->self->event_table, 0, sizeof(s->self->event_table[0]));
        s->self->event_table[0].type = STRACE_EVENT_NEXT;
        return (&s->self->event_table[0]);
    } else
        s->proc = STRACE_LIST_GET_ELEMENT(s->item, struct strace_process, event_list);
    return (sgne_exit(s));
}

static struct strace_event_data *sgne_do_loop(sgne_state_t *s)
{
    while (true) {
        if (s->pid < 0) {
            if (s->wait_errno == EINTR)
                break;
            if (s->wait_no_hang)
                break;
            if (!s->self->has_traced_process && s->wait_errno == ECHILD)
                return (NULL);
            errno = s->wait_errno;
            strace_print_error_message_errno_and_die(s->self, "wait4(0)");
        }
        if (s->pid == 0)
            break;
        s->proc = strace_process_get_from_pid(s->self, s->pid);
        if (s->proc != NULL) {
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
                switch (s->event) {
                case 0:
                    if (s->signal == SIGTRAP)
                        s->event_data->type = STRACE_EVENT_SINGLESTEP_STOPPED;
                    else {
                        s->stopped = ptrace(PTRACE_GETSIGINFO, s->pid, 0,
                            &s->event_data->signal_info) < 0;
                        s->event_data->type = s->stopped ?
                            STRACE_EVENT_SIGNAL_GROUP_STOPPED :
                            STRACE_EVENT_SIGNAL_DELIVERY_STOPPED;
                    }
                    break;
                case PTRACE_EVENT_STOP:
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
                    break;
                case PTRACE_EVENT_EXEC:
                    if (ptrace(PTRACE_GETEVENTMSG, s->pid, NULL,
                        &s->event_data->message) < 0)
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
            if (s->event_data->type == 0)
                strace_print_error_message(s->self, "Tracing event hasn't been "
                    "determined for pid %jd, status %0#x", s->pid,
                    s->wait_status);
            if (!strace_list_is_empty(&s->proc->event_list)) {
                s->self->gne_extra_index = s->event_table_position;
                s->self->gne_extra_proc = s->proc;
            } else {
                s->proc->event_data_index = s->event_table_position;
                strace_list_append(&s->self->gne_pending_procs, &s->proc->event_list);
            }
            ++s->event_table_position;
            if (s->self->gne_extra_proc != NULL)
                break;
        }
        s->pid = waitpid(-1, &s->wait_status, WNOHANG);
        s->wait_errno = errno;
        s->wait_no_hang = true;
    }
    return (sgne_get_proc(s));
}

static struct strace_event_data *sgne_part2(sgne_state_t *s)
{
    if (strace_list_is_empty(&s->self->gne_pending_procs)) {
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
void *strace_get_next_event(struct strace *self)
{
    sgne_state_t state = {
        .self = self,
        .event_table_position = 0,
    };

    return (sgne_part2(&state));
}
