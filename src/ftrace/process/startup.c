/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines process_startup
*/

#include "startup.h"
#include "../syscall/get_number.h"

// (TODO with entry stuff)
void ftrace_process_startup(struct ftrace *st, struct ftrace_process *self)
{
    self->flags &= ~STRACE_PROCESS_BEFORE_FIRST_STOP;
    if ((self->flags & STRACE_PROCESS_GRABBED) &&
        (ftrace_syscall_get_number(st, self) == 1))
        (void)0;
}
