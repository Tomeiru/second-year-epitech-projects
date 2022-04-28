/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_resume
*/

#include "print_resume.h"
#include "print_leader.h"
#include "../process/get_syscall_entry.h"
#include "../printf.h"

void ftrace_syscall_print_resume(struct ftrace *self,
    struct ftrace_process *proc)
{
    if (self->printing_process != proc) {
        ftrace_syscall_print_leader(self, proc);
        ftrace_printf(self, "<... %s resumed>",
            ftrace_process_get_syscall_entry(proc)->name);
    }
}
