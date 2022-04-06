/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines set_current_process
*/

#include "set_current_process.h"

void strace_set_current_process(struct strace *self,
    struct strace_process *proc)
{
    self->current_process = proc;
}
