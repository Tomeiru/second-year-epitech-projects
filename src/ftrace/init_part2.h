/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Part 2 of init
*/

#pragma once

#include "../ftrace.h"
#include "cstr_to_uint.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static inline void usage(struct ftrace *self)
{
    printf("Usage: %s [-hs] [-p PID]... { -p PID | PROG [ARGS] }\n",
        self->program_invocation_name);
    exit(0);
}

static inline void do_attach_list_loop_start(
    char *attach_list, char **delimiter, char *current_char, pid_t *pid)
{
    *delimiter = attach_list + strcspn(attach_list, "\n\t ,");
    *current_char = **delimiter;
    **delimiter = '\0';
    *pid = ftrace_cstr_to_uintmax(attach_list);
}
