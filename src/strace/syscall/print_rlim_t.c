/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_rlim_t
*/

#include "print_rlim_t.h"
#include "print_unsigned.h"
#include "../arr_sprintf.h"
#include <stddef.h>

void strace_syscall_print_rlim_t(struct strace *self, rlim_t rlim)
{
    const char *string = NULL;
    char buffer[sizeof(rlim) * 6 + sizeof("*1024")];

    if (rlim == RLIM64_INFINITY)
        string = "RLIM64_INFINITY";
    else if (rlim > 1024 && (rlim % 1024) == 0) {
        STRACE_ARR_SPRINTF(self, buffer, "%ju*1024", (uintmax_t)(rlim / 1024));
        string = buffer;
    }
    if (string == NULL) {
        STRACE_SYSCALL_PRINT_UNSIGNED(self, rlim);
        return;
    }
    strace_printf(self, "%s", string);
}
