/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines get_syscall_entry
*/

#include "get_syscall_entry.h"
#include "../syscall/stub_entry.h"
#include <stddef.h>

const struct strace_syscall_entry *strace_process_get_syscall_entry(
    struct strace_process *self)
{
    return (self->syscall_entry != NULL ? self->syscall_entry :
        &STRACE_SYSCALL_STUB_ENTRY);
}
