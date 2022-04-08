/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines access
*/

#include "../entries.h"
#include "../print_path.h"
#include "../print_next_argument.h"
#include "../print_flags.h"
#include <unistd.h>

static const struct strace_enum_data ACCESS_ENUM_DATA[] = {
    {F_OK, "F_OK"},
    {R_OK, "R_OK"},
    {W_OK, "W_OK"},
    {X_OK, "X_OK"},
};

static const struct strace_enum ACCESS_ENUM = {
    .data = ACCESS_ENUM_DATA,
    .size = sizeof(ACCESS_ENUM_DATA) / sizeof(ACCESS_ENUM_DATA[0]),
};

int strace_syscall_print_sys_access(struct strace *self,
    struct strace_process *proc)
{
    strace_syscall_print_path(self, proc, proc->syscall_arguments[0]);
    strace_syscall_print_next_argument(self);
    strace_syscall_print_flags(self, &ACCESS_ENUM, proc->syscall_arguments[1],
        "?_OK");
    return (STRACE_SYSCALL_RETVAL_DECODED);
}
