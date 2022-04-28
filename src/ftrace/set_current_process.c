/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines set_current_process
*/

#include "set_current_process.h"

void ftrace_set_current_process(struct ftrace *self,
    struct ftrace_process *proc)
{
    self->current_process = proc;
}
