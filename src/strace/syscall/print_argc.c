/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_argc
*/

#include "print_argc.h"
#include "print_argc_part2.h"
#include "print_address.h"
#include "../copy_mem_from_pid.h"
#include "../printf_comment.h"

static void sspa_part2(sspa_state_t *s)
{
    strace_syscall_print_address(s->self, s->address);
    if (s->address == 0)
        return;
    while (s->address > s->previous_address) {
        if (strace_copy_mem_from_pid(&((scmfp_opts_t){s->self, s->proc->pid,
            s->address, sizeof(s->w), &s->w}))) {
            if (s->i == 0)
                return;
            s->address = 0;
            break;
        }
        if (s->w == 0)
            break;
        s->previous_address = s->address;
        s->address += sizeof(s->w);
        ++s->i;
    }
    strace_printf_comment(s->self, "%zu var%s%s", s->i, s->i == 1 ? "" : "s",
        s->address < s->previous_address ? ", unterminated" : "");
}

void strace_syscall_print_argc(struct strace *self,
    struct strace_process *proc, __kernel_ulong_t address)
{
    sspa_state_t state = {
        .self = self,
        .proc = proc,
        .address = address,
        .i = 0,
    };

    sspa_part2(&state);
}
