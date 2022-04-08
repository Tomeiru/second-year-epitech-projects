/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_string_n
*/

#include "print_string_ex.h"
#include "print_string_ex_part2.h"
#include "print_more_data_after_this.h"
#include "print_address.h"
#include "../printf.h"
#include "../malloc.h"
#include "../copy_str_from_pid.h"
#include "../copy_mem_from_pid.h"
#include "../quote_string.h"
#include <stdlib.h>

static int sspse_part3(sspse_state_t *s)
{
    if (s->size > 32)
        s->size = 32;
    else
        s->string[s->size] = '\xff';
    s->printed_all = strace_quote_string(&((sqs_opts_t){s->self, s->string,
        s->output_string, s->size, s->style})) &&
        s->length != 0 && ((s->style & STRACE_SYSCALL_PRINT_QUOTE_0_TERM) ||
        s->length > 32);
    strace_printf(s->self, "%s", s->output_string);
    if (s->printed_all != 0)
        strace_syscall_print_more_data_after_this(s->self);
    return (s->r);
}

static int sspse_part2(sspse_state_t *s)
{
    if (s->size > s->length)
        s->size = s->length;
    if (s->style & STRACE_SYSCALL_PRINT_QUOTE_0_TERM)
        s->r = strace_copy_str_from_pid(&((scsfp_opts_t){
            s->self, s->proc->pid, s->address, s->size, s->string }));
    else
        s->r = strace_copy_mem_from_pid(&((scmfp_opts_t){
            s->self, s->proc->pid, s->address, s->size, s->string }));
    if (s->r < 0) {
        strace_syscall_print_address(s->self, s->address);
        return (s->r);
    }
    return (sspse_part3(s));
}

int strace_syscall_print_string_ex(sspse_opts_t *o)
{
    sspse_state_t state = {
        .self = o->self,
        .proc = o->proc,
        .address = o->address,
        .length = o->length,
        .style = o->style,
        .size = 32 + 1,
    };

    if (state.address == 0) {
        strace_printf(state.self, "NULL");
        return (-1);
    }
    return (sspse_part2(&state));
}
