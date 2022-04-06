/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_argv
*/

#include "print_argv.h"
#include "print_argv_part2.h"
#include "print_address.h"
#include "print_array_begin.h"
#include "print_array_next.h"
#include "print_array_end.h"
#include "print_more_data_after_this.h"
#include "print_address_comment.h"
#include "print_string.h"
#include "../copy_mem_from_pid.h"

static bool do_after_copy_mem_fail(struct strace *self,
    __kernel_ulong_t address, size_t i)
{
    if (i == 0) {
        strace_syscall_print_address(self, address);
        return (false);
    }
    strace_syscall_print_array_next(self);
    strace_syscall_print_more_data_after_this(self);
    strace_syscall_print_address_comment(self, address);
    return (true);
}

bool do_it_part2(sspa_state_t *s)
{
    if (s->i == 0)
        strace_syscall_print_array_begin(s->self);
    if (s->c.ul == 0)
        return (false);
    if (s->i != 0)
        strace_syscall_print_array_next(s->self);
    if (s->i >= 32) {
        strace_syscall_print_more_data_after_this(s->self);
        return (false);
    }
    strace_syscall_print_string(s->self, s->proc, s->c.ul);
    s->previous_address = s->address;
    s->address += sizeof(__kernel_ulong_t);
    ++s->i;
    return (true);
}

void sspap2_part2(sspa_state_t *s)
{
    if (s->address == 0) {
        strace_syscall_print_address(s->self, s->address);
        return;
    }
    while (true) {
        if (s->address < s->previous_address || strace_copy_mem_from_pid(
            &((scmfp_opts_t){s->self, s->proc->pid, s->address,
            sizeof(s->c.data), s->c.data}))) {
            if (!do_after_copy_mem_fail(s->self, s->address, s->i))
                return;
            break;
        }
        if (!do_it_part2(s))
            break;
    }
    strace_syscall_print_array_end(s->self);
}

void strace_syscall_print_argv(struct strace *self, struct strace_process *proc,
    __kernel_ulong_t address)
{
    sspa_state_t state = {
        .self = self,
        .proc = proc,
        .address = address,
        .previous_address = 0,
        .i = 0,
    };

    sspap2_part2(&state);
}
