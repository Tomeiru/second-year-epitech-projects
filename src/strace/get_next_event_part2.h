/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Part 2 of get_next_event
*/

#pragma once

#include "../strace.h"

typedef struct sgne_state {
    struct strace *self;
    int wait_status;
    pid_t pid;
    int wait_errno;
    struct strace_process *proc;
    size_t event_table_position;
    struct strace_event_data *event_data;
    unsigned signal;
    unsigned event;
    bool stopped;
    bool wait_no_hang;
    struct strace_list_item *item;
} sgne_state_t;
