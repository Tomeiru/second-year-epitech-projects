/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines syscall_get_number
*/

#include "get_number.h"
#include "number_is_valid.h"
#include "entries.h"
#include "stub_entry.h"
#include "entry_buffer_free.h"
#include "../get_regs.h"
#include "../print_error_message.h"
#include "../zalloc.h"
#include "../process/set_private_data.h"
#include "../arr_sprintf.h"
#include <sys/ptrace.h>
#include <linux/posix_types.h>
#include <stdint.h>
#include <stddef.h>

// x86-64 syscall instruction is 0x50F
static int check_x86_stuff(struct strace *self, struct strace_process *proc)
{
    long instruction = ptrace(PTRACE_PEEKTEXT, proc->pid,
        (void *)self->x86_regs.rip, (void *)NULL);

    if ((instruction & 0xFFFF) != 0x50F)
        return (0);
    if (self->x86_io.iov_len != sizeof(self->x86_regs)) {
        strace_print_error_message(self, "Unsupported 32-bit mode of"
            "process PID=%j", (intmax_t)proc->pid);
        return (0);
    }
    proc->syscall_number = self->x86_regs.rax;
    return (1);
}

static int ssgn_part2(struct strace *self, struct strace_process *proc)
{
    struct strace_syscall_entry_buffer *p;

    if (strace_syscall_number_is_valid(proc->syscall_number)) {
        proc->syscall_entry = &STRACE_SYSCALL_ENTRIES[proc->syscall_number];
        proc->qualifier_flags = 0;
    } else {
        p = strace_zalloc(self, sizeof(*p));
        p->proc = proc;
        p->entry = STRACE_SYSCALL_STUB_ENTRY;
        p->entry.name = p->buffer;
        STRACE_ARR_SPRINTF(self, p->buffer, "syscall_%#jx",
            (intmax_t)proc->syscall_number);
        proc->syscall_entry = &p->entry;
        strace_process_set_private_data(proc, p,
            strace_syscall_entry_buffer_free);
    }
    if (proc->flags & STRACE_PROCESS_RECOVERING)
        proc->qualifier_flags &= STRACE_QUALIFIER_RAW;
    return (1);
}

int strace_syscall_get_number(struct strace *self, struct strace_process *proc)
{
    int r;

    proc->syscall_number = -1;
    proc->syscall_entry = NULL;
    proc->qualifier_flags = STRACE_QUALIFIER_RAW;
    if (strace_get_regs(self, proc) < 0)
        return (-1);
    r = check_x86_stuff(self, proc);
    if (r != 1)
        return (r);
    return (ssgn_part2(self, proc));
}
