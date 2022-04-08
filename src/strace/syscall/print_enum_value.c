/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_enum_value
*/

#include "print_enum_value.h"
#include "../enum_lookup.h"
#include "../printf.h"
#include "../printf_comment.h"
#include <stddef.h>

int strace_syscall_print_enum_value(struct strace *self,
    const struct strace_enum *enu, uintmax_t value, const char *default_string)
{
    const char *string = strace_enum_lookup(enu, value);

    if (string != NULL) {
        strace_printf(self, "%s", string);
        return (1);
    }
    strace_printf(self, "%#jx", value);
    strace_printf_comment(self, "%s", default_string);
    return (0);
}
