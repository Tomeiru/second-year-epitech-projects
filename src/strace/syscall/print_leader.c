/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_leader
*/

#include "print_leader.h"
#include "../set_current_process.h"
#include <stddef.h>

void strace_syscall_print_leader(struct strace *self,
    struct strace_process *proc)
{
    if (self->printing_process != NULL)
        strace_set_current_process(self, proc);
    self->printing_process = proc;
    strace_set_current_process(self, proc);
    self->current_process->current_column = 0;
}
