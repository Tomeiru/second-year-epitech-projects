/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_string
*/

#include "print_string.h"
#include "print_string_part2.h"
#include "print_more_data_after_this.h"
#include "print_address.h"
#include "../printf.h"
#include "../malloc.h"
#include "../copy_str_from_pid.h"
#include "../quote_string.h"
#include <stdlib.h>

static int ssps_part2(sspsp2_opts_t *o)
{
    size_t size = 32 + 1;
    int r = strace_copy_str_from_pid(&((scsfp_opts_t){o->self, o->proc->pid,
        o->address, size, o->string}));
    int printed_all;

    if (r < 0) {
        strace_syscall_print_address(o->self, o->address);
        return (r);
    }
    if (size > 32)
        size = 32;
    printed_all = strace_quote_string(&((sqs_opts_t){o->self, o->string,
        o->output_string, size, STRACE_SYSCALL_PRINT_QUOTE_0_TERM}));
    strace_printf(o->self, "%s", o->output_string);
    if (printed_all != 0)
        strace_syscall_print_more_data_after_this(o->self);
    return (r);
}

int strace_syscall_print_string(struct strace *self,
    struct strace_process *proc, __kernel_ulong_t address)
{
    char string[32 + 1];
    char output_string[4 * 32 + 3];

    if (address == 0) {
        strace_printf(self, "NULL");
        return (-1);
    }
    return (ssps_part2(&((sspsp2_opts_t){self, proc, address, string,
        output_string})));
}
