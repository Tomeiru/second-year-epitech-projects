/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_resume
*/

#include "print_resume.h"
#include "print_leader.h"
#include "../process/get_syscall_entry.h"
#include "../printf.h"

void strace_syscall_print_resume(
    struct strace *self, struct strace_process *proc)
{
    if (self->printing_process != proc) {
        strace_syscall_print_leader(self, proc);
        strace_printf(self, "<... %s resumed>",
            strace_process_get_syscall_entry(proc)->name);
    }
}
