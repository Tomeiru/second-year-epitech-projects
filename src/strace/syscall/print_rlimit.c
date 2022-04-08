/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_rlimit
*/

#include "print_rlimit.h"
#include "copy_mem_or_print_address.h"
#include "print_struct_start.h"
#include "print_struct_next.h"
#include "print_struct_end.h"
#include "print_rlim_t.h"
#include "../printf.h"
#include <sys/resource.h>

void strace_syscall_print_rlimit(
    struct strace *self, struct strace_process *proc, __syscall_ulong_t address)
{
    struct rlimit rlimit_buffer;

    if (strace_syscall_copy_mem_or_print_address(&((sscmopa_opts_t){self, proc,
        address, sizeof(rlimit_buffer), &rlimit_buffer})) == 0) {
        strace_syscall_print_struct_start(self);
        strace_printf(self, "rlim_cur=");
        strace_syscall_print_rlim_t(self, rlimit_buffer.rlim_cur);
        strace_syscall_print_struct_next(self);
        strace_printf(self, "rlim_max=");
        strace_syscall_print_rlim_t(self, rlimit_buffer.rlim_max);
        strace_syscall_print_struct_end(self);
    }
}
