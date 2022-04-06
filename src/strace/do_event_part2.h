/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Part 2 of do_event
*/

#pragma once

#include "../strace.h"

typedef struct sde_state {
    struct strace *self;
    const struct strace_event_data *event_data;
    enum strace_event_type event_type;
    unsigned restart_signal;
    int wait_status;
    unsigned restart_operation;
    int r;
} sde_state_t;
