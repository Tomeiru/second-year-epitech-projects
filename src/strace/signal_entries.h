/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines signal_entries
*/

#pragma once

#include <stddef.h>

static const char *STRACE_SIGNAL_ENTRIES[] = {};
static size_t STRACE_SIGNAL_ENTRIES_COUNT = (sizeof(STRACE_SIGNAL_ENTRIES) /
    sizeof(STRACE_SIGNAL_ENTRIES[0]));
