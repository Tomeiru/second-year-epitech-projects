/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares quote_string
*/

#pragma once

#include "../ftrace.h"

typedef struct sqs_opts {
    struct ftrace *self;
    const char *in_string;
    char *out_string;
    size_t size;
    unsigned style;
} sqs_opts_t;

int ftrace_quote_string(sqs_opts_t *o);
