/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines do_exec
*/

#include "do_exec.h"
#include "print_error_message/errno_and_die.h"
#include <unistd.h>
#include <signal.h>
#include <sys/ptrace.h>

// We let the parent trace us by raising SIGSTOP (we want our parent to be able
// to see us do the execve)
void ftrace_do_exec(struct ftrace *self)
{
    if (geteuid() != 0)
        if (setreuid(self->traced_process_uid, self->traced_process_uid) < 0)
            ftrace_print_error_message_errno_and_die(self, "setreuid");
    raise(SIGSTOP);
    if (self->traced_process_params.sigchld_sigaction.sa_handler != SIG_DFL)
        sigaction(SIGCHLD, &self->traced_process_params.sigchld_sigaction,
            NULL);
    execv(self->traced_process_params.exec_pathname,
        self->traced_process_params.argv);
    ftrace_print_error_message_errno_and_die(self, "exec");
}
