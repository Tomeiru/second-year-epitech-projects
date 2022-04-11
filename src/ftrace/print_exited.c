/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_exited
*/

#include "print_exited.h"
#include "printf.h"
#include "syscall/print_leader.h"
#include "syscall/print_line_ended.h"
#include <sys/wait.h>

void ftrace_print_exited(struct ftrace *self, struct ftrace_process *proc,
    pid_t pid, int wait_status)
{
    if (pid == self->child_pid) {
        self->exit_status = WEXITSTATUS(wait_status);
        self->child_pid = 0;
    }
    ftrace_syscall_print_leader(self, proc);
    ftrace_printf(self, "+++ exited with %d +++\n", WEXITSTATUS(wait_status));
    ftrace_syscall_print_line_ended(self);
}
