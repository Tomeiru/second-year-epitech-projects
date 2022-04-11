/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_enum_value
*/

#include "print_enum_value.h"
#include "../enum_lookup.h"
#include "../printf.h"
#include "../printf_comment.h"
#include <stddef.h>

int ftrace_syscall_print_enum_value(struct ftrace *self,
    const struct ftrace_enum *enu, uintmax_t value, const char *default_string)
{
    const char *string = ftrace_enum_lookup(enu, value);

    if (string != NULL) {
        ftrace_printf(self, "%s", string);
        return (1);
    }
    ftrace_printf(self, "%#jx", value);
    ftrace_printf_comment(self, "%s", default_string);
    return (0);
}
