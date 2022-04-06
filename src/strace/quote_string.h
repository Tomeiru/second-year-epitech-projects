/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares quote_string
*/

#pragma once

#include "../strace.h"

typedef struct sqs_opts {
    struct strace *self;
    const char *in_string;
    char *out_string;
    size_t size;
    unsigned style;
} sqs_opts_t;

int strace_quote_string(sqs_opts_t *o);
