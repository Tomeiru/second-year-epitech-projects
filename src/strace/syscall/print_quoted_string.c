/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_quoted_string
*/

#include "print_quoted_string.h"
#include "print_quoted_string_part2.h"
#include "print_unavailable.h"
#include "../print_error_message.h"
#include "../quote_string.h"
#include "../printf.h"
#include <stdlib.h>

static int sspqs_part2(sspqsp2_opts_t *o)
{
    int r;

    if (o->buffer == NULL) {
        strace_print_error_message(o->self, "Memory exhausted while trying to "
            "allocate %zu bytes", o->allocation_size);
        strace_syscall_print_unavailable(o->self);
        return (-1);
    }
    r = strace_quote_string(&((sqs_opts_t){o->self, o->string, o->out_string,
        o->size, o->style}));
    strace_printf(o->self, "%s", o->out_string);
    free(o->buffer);
    return (r);
}

int strace_syscall_print_quoted_string(
    struct strace *self, const char *string, size_t size, unsigned style)
{
    char *buffer;
    char *out_string;
    size_t allocation_size;

    if (size != 0 && (style & STRACE_SYSCALL_PRINT_QUOTE_0_TERM))
        --size;
    allocation_size = size * 4;
    if (allocation_size / 4 != size) {
        strace_print_error_message(self, "requested %zu bytes exceeds %zu "
            "bytes limit", size, -(size_t)1u / 4);
        strace_syscall_print_unavailable(self);
        return (-1);
    }
    allocation_size += 1 + 2;
    buffer = malloc(allocation_size);
    out_string = buffer;
    return (sspqs_part2(&((sspqsp2_opts_t){self, string, size, style, buffer,
        out_string, allocation_size})));
}
