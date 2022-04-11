/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines do_ptrace_seize
*/

#include "do_ptrace_seize.h"
#include <sys/ptrace.h>

int ftrace_do_ptrace_seize(
    struct ftrace *self, pid_t pid, const char **ptrace_command)
{
    int result = ptrace(PTRACE_SEIZE, pid, 0L,
        (unsigned long)(PTRACE_O_TRACEEXEC | PTRACE_O_TRACEEXIT));

    (void)self;
    if (result != 0) {
        *ptrace_command = "PTRACE_SEIZE";
        return (result);
    }
    *ptrace_command = "PTRACE_INTERRUPT";
    return (ptrace(PTRACE_INTERRUPT, pid, 0L, 0L));
}
