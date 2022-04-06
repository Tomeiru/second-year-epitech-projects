/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Part 2 of quote_string
*/

#pragma once

#include "quote_string.h"

typedef struct dc_opts {
    sqs_opts_t *o;
    char **os_ptr;
    int current_character;
    size_t i;
    const unsigned char *const uc_in_string;
} dc_opts_t;
