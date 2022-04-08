/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines do_ptrace_seize
*/

#include "do_ptrace_seize.h"
#include <sys/ptrace.h>

int strace_do_ptrace_seize(
    struct strace *self, pid_t pid, const char **ptrace_command)
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
