/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines do_event
*/

#include "do_event.h"
#include "do_trace_syscall.h"
#include "print_error_message.h"
#include "print_signal_stop.h"
#include "print_signalled.h"
#include "print_exited.h"
#include "print_event_exit_stopped.h"
#include "do_ptrace_restart.h"
#include "process/drop.h"
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <stdint.h>
#include <stddef.h>

bool strace_do_event(struct strace *self,
    const struct strace_event_data *event_data)
{
    enum strace_event_type event_type = event_data != NULL ? event_data->type :
        STRACE_EVENT_BREAK_MAIN_LOOP;
    unsigned restart_signal = 0;
    int wait_status = event_data != NULL ? event_data->wait_status : 0;
    unsigned restart_operation = PTRACE_SINGLESTEP;

    switch (event_type) {
    case STRACE_EVENT_BREAK_MAIN_LOOP:
        return (false);
    case STRACE_EVENT_NEXT:
        return (true);
    case STRACE_EVENT_RESTART:
        break;
    case STRACE_EVENT_SINGLESTEP_STOPPED:
        if (strace_do_trace_syscall(self, self->current_process) < 0)
            return (true);
        break;
    case STRACE_EVENT_SIGNAL_DELIVERY_STOPPED:
        restart_signal = WSTOPSIG(wait_status);
        strace_print_signal_stop(self, self->current_process,
            &event_data->signal_info, restart_signal);
        break;
    case STRACE_EVENT_SIGNALLED:
        strace_print_signalled(self, self->current_process,
            self->current_process->pid, wait_status);
        strace_process_drop(self, self->current_process);
        return (true);
    case STRACE_EVENT_SIGNAL_GROUP_STOPPED:
        strace_print_signal_stop(self, self->current_process, NULL,
            restart_signal);
        restart_operation = PTRACE_LISTEN;
        restart_signal = 0;
        break;
    case STRACE_EVENT_EXITED:
        strace_print_exited(self, self->current_process,
            self->current_process->pid, wait_status);
        strace_process_drop(self, self->current_process);
        return (true);
    case STRACE_EVENT_BEFORE_EXECVE_STOPPED:
        self->current_process->flags &= ~STRACE_PROCESS_CHECK_EXEC_SUCCESS;
        if (!(self->current_process->flags & STRACE_PROCESS_IN_SYSCALL)) {
            strace_print_error_message(self, "Stay PTRACE_EVENT_EXEC from pid "
                "%jd, trying to recover...",
                (intmax_t)self->current_process->pid);
            self->current_process->flags |= STRACE_PROCESS_RECOVERING;

            int r = strace_do_trace_syscall(self, self->current_process);

            self->current_process->flags &= ~STRACE_PROCESS_RECOVERING;
            if (r < 0)
                return (true);
        }
        break;
    case STRACE_EVENT_BEFORE_EXIT_STOPPED:
        strace_print_event_exit_stopped(self, self->current_process);
        break;
    }
    if (strace_do_ptrace_restart(self, restart_operation, self->current_process,
        restart_signal) < 0) {
        self->exit_status = 1;
        return (false);
    }
    return (true);
}
