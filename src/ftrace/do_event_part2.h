/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Part 2 of do_event
*/

#pragma once

#include "../ftrace.h"

typedef struct sde_state {
    struct ftrace *self;
    const struct ftrace_event_data *event_data;
    enum ftrace_event_type event_type;
    unsigned restart_signal;
    int wait_status;
    unsigned restart_operation;
    int r;
} sde_state_t;
