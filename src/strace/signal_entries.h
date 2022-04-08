/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines signal_entries
*/

#pragma once

#include <signal.h>
#include <stddef.h>

static const char *STRACE_SIGNAL_ENTRIES[] = {
    [0] = "0",
    [SIGHUP] = "SIGHUP",
    [SIGINT] = "SIGINT",
    [SIGQUIT] = "SIGQUIT",
    [SIGILL] = "SIGILL",
    [SIGTRAP] = "SIGTRAP",
    [SIGABRT] = "SIGABRT",
    [SIGBUS] = "SIGBUS",
    [SIGFPE] = "SIGFPE",
    [SIGKILL] = "SIGKILL",
    [SIGUSR1] = "SIGUSR1",
    [SIGSEGV] = "SIGSEGV",
    [SIGUSR2] = "SIGUSR2",
    [SIGPIPE] = "SIGPIPE",
    [SIGALRM] = "SIGALRM",
    [SIGTERM] = "SIGTERM",
    [SIGSTKFLT] = "SIGSTKFLT",
    [SIGCHLD] = "SIGCHLD",
    [SIGCONT] = "SIGCONT",
    [SIGSTOP] = "SIGSTOP",
    [SIGTSTP] = "SIGTSTP",
    [SIGTTIN] = "SIGTTIN",
    [SIGTTOU] = "SIGTTOU",
    [SIGURG] = "SIGURG",
    [SIGXCPU] = "SIGXCPU",
    [SIGXFSZ] = "SIGXFSZ",
    [SIGVTALRM] = "SIGVTALRM",
    [SIGPROF] = "SIGPROF",
    [SIGWINCH] = "SIGWINCH",
    [SIGIO] = "SIGIO",
    [SIGPWR] = "SIGPWR",
    [SIGSYS] = "SIGSYS",
    [__SIGRTMIN] = "SIGRTMIN",
};
static size_t STRACE_SIGNAL_ENTRIES_COUNT =
    (sizeof(STRACE_SIGNAL_ENTRIES) / sizeof(STRACE_SIGNAL_ENTRIES[0]));
