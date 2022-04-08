/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines quote_string
*/

#include "quote_string.h"
#include "quote_string_part2.h"
#include "sprint_byte_hex.h"

static int string_ended(sqs_state_t *s)
{
    *s->os_ptr++ = '"';
    *s->os_ptr = '\0';
    return (!((s->o->style & STRACE_SYSCALL_PRINT_QUOTE_0_TERM) &&
        s->uc_in_string[s->i] == '\0'));
}

static int hex_quote_whole_string(sqs_state_t *s)
{
    for (s->i = 0; s->i < s->o->size; ++s->i) {
        s->current_character = s->uc_in_string[s->i];
        if (s->current_character == s->end_of_string)
            return (c_string_ended(s->os_ptr));
        *s->os_ptr++ = '\\';
        *s->os_ptr++ = 'x';
        s->os_ptr = strace_sprint_byte_hex(s->os_ptr, s->current_character);
    }
    return (string_ended(s));
}

static int sqs_part2(sqs_state_t *s)
{
    *s->os_ptr++ = '"';
    if (s->use_hex)
        return (hex_quote_whole_string(s));
    for (s->i = 0; s->i < s->o->size; ++s->i) {
        s->current_character = s->uc_in_string[s->i];
        if (s->current_character == s->end_of_string)
            return (c_string_ended(s->os_ptr));
        do_char(s);
    }
    return (string_ended(s));
}

int strace_quote_string(sqs_opts_t *o)
{
    sqs_state_t state = {
        .o = o,
        .end_of_string = (o->style & STRACE_SYSCALL_PRINT_QUOTE_0_TERM) ? '\0' :
            0x100,
        .os_ptr = o->out_string,
        .uc_in_string = (const unsigned char *)o->in_string,
        .hex_style = (o->style & STRACE_SYSCALL_PRINT_QUOTE_HEX_STRING) ?
            ((o->style & STRACE_SYSCALL_PRINT_QUOTE_HEX_STRING_MASK) >>
                STRACE_SYSCALL_PRINT_QUOTE_HEX_STRING_SHIFT) :
            STRACE_HEX_STRING_NONE,
    };

    state.use_hex = state.hex_style == STRACE_HEX_STRING_ALL;
    return (sqs_part2(&state));
}
