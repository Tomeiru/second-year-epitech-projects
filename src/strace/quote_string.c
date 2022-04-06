/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines quote_string
*/

#include "quote_string.h"
#include "quote_string_part2.h"
#include "is_printable.h"
#include "sprint_byte_octal.h"

static int c_string_ended(char *os_ptr)
{
    *os_ptr++ = '"';
    *os_ptr = '\0';
    return (0);
}

static void do_char_part3(dc_opts_t *o)
{
    if (o->current_character == '\v') {
        *((*o->os_ptr)++) = '\\';
        *((*o->os_ptr)++) = 'v';
        return;
    }
    if (strace_is_printable(o->current_character))
        *((*o->os_ptr)++) = o->current_character;
    else {
        *((*o->os_ptr)++) = '\\';
        *o->os_ptr = strace_sprint_byte_octal(*o->os_ptr, o->current_character,
            o->i + 1 < o->o->size && o->uc_in_string[o->i + 1] >= '0' &&
            o->uc_in_string[o->i + 1] <= '7');
    }
}

static void do_char_part2(dc_opts_t *o)
{
    if (o->current_character == '\r') {
        *((*o->os_ptr)++) = '\\';
        *((*o->os_ptr)++) = 'r';
        return;
    }
    if (o->current_character == '\t') {
        *((*o->os_ptr)++) = '\\';
        *((*o->os_ptr)++) = 't';
        return;
    }
    do_char_part3(o);
}

static void do_char(dc_opts_t *o)
{
    if (o->current_character == '"' || o->current_character == '\\') {
        *((*o->os_ptr)++) = '\\';
        *((*o->os_ptr)++) = o->current_character;
        return;
    }
    if (o->current_character == '\f') {
        *((*o->os_ptr)++) = '\\';
        *((*o->os_ptr)++) = 'f';
        return;
    }
    if (o->current_character == '\n') {
        *((*o->os_ptr)++) = '\\';
        *((*o->os_ptr)++) = 'n';
        return;
    }
    do_char_part2(o);
}

int strace_quote_string(sqs_opts_t *o)
{
    int end_of_string = (o->style & STRACE_SYSCALL_PRINT_QUOTE_0_TERM) ? '\0' :
        0x100;
    char *os_ptr = o->out_string;
    int current_character;
    const unsigned char *const uc_in_string =
        (const unsigned char *)o->in_string;
    size_t i;

    *os_ptr++ = '"';
    for (i = 0; i < o->size; ++i) {
        current_character = uc_in_string[i];
        if (current_character == end_of_string)
            return (c_string_ended(os_ptr));
        do_char(&((dc_opts_t){o, &os_ptr, current_character, i, uc_in_string}));
    }
    *os_ptr++ = '"';
    *os_ptr = '\0';
    return (!((o->style & STRACE_SYSCALL_PRINT_QUOTE_0_TERM) &&
        uc_in_string[i] == '\0'));
}
