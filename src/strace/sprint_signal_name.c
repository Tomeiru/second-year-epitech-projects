/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines sprint_signal_name
*/

#include "sprint_signal_name.h"
#include "get_signal_name.h"
#include "arr_sprintf.h"
#include <stddef.h>

const char *strace_sprint_signal_name(struct strace *self, int signal)
{
    const char *string = strace_get_signal_name(self, signal);
    static char buffer[sizeof(signal) * 6 + 4];

    if (string != NULL)
        return (string);
    STRACE_ARR_SPRINTF(self, buffer, "%d", signal);
    return (buffer);
}
