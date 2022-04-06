/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines process_startup
*/

#include "startup.h"
#include "../syscall/get_number.h"

// (TODO with entry stuff)
void strace_process_startup(struct strace *st, struct strace_process *self)
{
    self->flags &= ~STRACE_PROCESS_BEFORE_FIRST_STOP;
    if ((self->flags & STRACE_PROCESS_GRABBED) && (strace_syscall_get_number(st,
        self) == 1))
        (void)0;
}
