/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Part 2 of quote_string
*/

#pragma once

#include "quote_string.h"
#include "is_printable.h"
#include "sprint_byte_octal.h"

typedef struct sqs_state {
    sqs_opts_t *o;
    int end_of_string;
    char *os_ptr;
    int current_character;
    const unsigned char *const uc_in_string;
    size_t i;
    enum ftrace_hex_string_style hex_style;
    bool use_hex;
} sqs_state_t;

static inline int c_string_ended(char *os_ptr)
{
    *os_ptr++ = '"';
    *os_ptr = '\0';
    return (0);
}

static inline void do_char_part3(sqs_state_t *s)
{
    if (s->current_character == '\v') {
        *(s->os_ptr++) = '\\';
        *(s->os_ptr++) = 'v';
        return;
    }
    if (ftrace_is_printable(s->current_character))
        *(s->os_ptr++) = s->current_character;
    else {
        *(s->os_ptr++) = '\\';
        s->os_ptr = ftrace_sprint_byte_octal(s->os_ptr, s->current_character,
            s->i + 1 < s->o->size && s->uc_in_string[s->i + 1] >= '0' &&
            s->uc_in_string[s->i + 1] <= '7');
    }
}

static inline void do_char_part2(sqs_state_t *s)
{
    if (s->current_character == '\r') {
        *(s->os_ptr++) = '\\';
        *(s->os_ptr++) = 'r';
        return;
    }
    if (s->current_character == '\t') {
        *(s->os_ptr++) = '\\';
        *(s->os_ptr++) = 't';
        return;
    }
    do_char_part3(s);
}

static inline void do_char(sqs_state_t *s)
{
    if (s->current_character == '"' || s->current_character == '\\') {
        *(s->os_ptr++) = '\\';
        *(s->os_ptr++) = s->current_character;
        return;
    }
    if (s->current_character == '\f') {
        *(s->os_ptr++) = '\\';
        *(s->os_ptr++) = 'f';
        return;
    }
    if (s->current_character == '\n') {
        *(s->os_ptr++) = '\\';
        *(s->os_ptr++) = 'n';
        return;
    }
    do_char_part2(s);
}
