/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_flags
*/

#include "print_flags.h"
#include "print_unsigned.h"
#include "../printf.h"
#include "../printf_comment.h"
#include <stddef.h>

int strace_syscall_print_flags(struct strace *self,
    const struct strace_enum *enu, uintmax_t flags, const char *default_string)
{
    size_t j = 0;
    uintmax_t val;

    for (size_t i = 0; (flags || j == 0) && i < enu->size; ++i) {
        val = enu->data[i].value;
        if (enu->data[i].string != NULL &&
            ((flags == val) || (val != 0 && (flags & val) == val))) {
            if (j++)
                strace_printf(self, "|");
            strace_printf(self, "%s", enu->data[i].string);
            flags &= ~val;
        }
        if (flags == 0)
            break;
    }
    if (j != 0) {
        if (flags != 0) {
            strace_printf(self, "|");
            strace_printf(self, "%#jx", flags);
            ++j;
        }
    } else {
        if (flags != 0) {
            strace_printf(self, "%#jx", flags);
            strace_printf_comment(self, "%s", default_string);
        } else if (default_string != NULL)
            STRACE_SYSCALL_PRINT_UNSIGNED(self, 0);
    }
    return (j);
}
