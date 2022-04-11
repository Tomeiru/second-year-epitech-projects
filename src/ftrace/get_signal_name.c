/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines get_signal_name
*/

#include "get_signal_name.h"
#include "signal_entries.h"
#include "arr_sprintf.h"
#include <stddef.h>

const char *ftrace_get_signal_name(struct ftrace *self, unsigned signal)
{
    static char buffer[sizeof("SIGRT_%u") + sizeof(signal) * 6];

    if (signal <= 0)
        return (NULL);
    if (signal < STRACE_SIGNAL_ENTRIES_COUNT)
        return STRACE_SIGNAL_ENTRIES[signal];
    if (signal >= __SIGRTMIN && signal <= (unsigned)__SIGRTMAX) {
        STRACE_ARR_SPRINTF(self, buffer, "SIGRT_%u", signal - __SIGRTMIN);
        return (buffer);
    }
    return (NULL);
}
