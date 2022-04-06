/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines syscall_enter_decode
*/

#include "enter_decode.h"
#include "get_number.h"
#include "print_leader.h"
#include "print_start_arguments.h"
#include "get_arguments.h"
#include "../process/get_syscall_entry.h"

static bool get_args(struct strace *self, struct strace_process *proc, int *r)
{
    *r = strace_syscall_get_arguments(self, proc);
    return (*r == 1);
}

int strace_syscall_enter_decode(struct strace *self,
    struct strace_process *proc)
{
    int r = strace_syscall_get_number(self, proc);

    if (r == 0)
        return (0);
    if (r != 1 || !get_args(self, proc, &r)) {
        strace_syscall_print_leader(self, proc);
        strace_syscall_print_start_arguments(self,
            strace_process_get_syscall_entry(proc)->name);
        return (r);
    }
    return (1);
}
