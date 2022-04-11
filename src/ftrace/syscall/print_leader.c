/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_leader
*/

#include "print_leader.h"
#include "../set_current_process.h"
#include <stddef.h>

void ftrace_syscall_print_leader(
    struct ftrace *self, struct ftrace_process *proc)
{
    if (self->printing_process != NULL)
        ftrace_set_current_process(self, proc);
    self->printing_process = proc;
    ftrace_set_current_process(self, proc);
    self->current_process->current_column = 0;
}
