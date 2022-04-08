/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_signalled
*/

#include "print_signalled.h"
#include "printf.h"
#include "sprint_signal_name.h"
#include "syscall/print_leader.h"
#include "syscall/print_line_ended.h"
#include <sys/wait.h>

void strace_print_signalled(struct strace *self, struct strace_process *proc,
    pid_t pid, int wait_status)
{
    if (pid == self->child_pid) {
        self->exit_status = 0x100 | WTERMSIG(wait_status);
        self->child_pid = 0;
    }
    strace_syscall_print_leader(self, proc);
    strace_printf(self, "+++ killed by %s %s+++\n",
        strace_sprint_signal_name(self, WTERMSIG(wait_status)),
        WCOREDUMP(wait_status) ? "(core dumped) " : "");
    strace_syscall_print_line_ended(self);
}
