/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines syscall_enter_decode
*/

#include "enter_decode.h"
#include "get_number.h"
#include "print_leader.h"
#include "print_start_arguments.h"
#include "get_arguments.h"
#include "../process/get_syscall_entry.h"
#include "../printf.h"

static bool get_args(struct ftrace *self, struct ftrace_process *proc, int *r)
{
    *r = ftrace_syscall_get_arguments(self, proc);
    return (*r == 1);
}

int ftrace_syscall_enter_decode(struct ftrace *self,
    struct ftrace_process *proc)
{
    int r = ftrace_syscall_get_number(self, proc);

    if (r == 0)
        return (0);
    if (r != 1 || !get_args(self, proc, &r)) {
        ftrace_syscall_print_leader(self, proc);
        ftrace_syscall_print_start_arguments(self,
            ftrace_process_get_syscall_entry(proc)->name);
        return (r);
    }
    return (1);
}
