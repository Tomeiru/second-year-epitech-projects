/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines getrandom
*/

#include "../entries.h"
#include "../print_address.h"
#include "../print_string_ex.h"
#include "../print_next_argument.h"
#include "../print_unsigned.h"
#include "../print_flags.h"
#include <sys/random.h>

static const struct ftrace_enum_data FLAGS_ENUM_DATA[] = {
    {GRND_NONBLOCK, "GRND_NONBLOCK"},
    {GRND_RANDOM, "GRND_RANDOM"},
    {GRND_INSECURE, "GRND_INSECURE"},
};

static const struct ftrace_enum FLAGS_ENUM = {
    .data = FLAGS_ENUM_DATA,
    .size = sizeof(FLAGS_ENUM_DATA) / sizeof(FLAGS_ENUM_DATA[0]),
};

int ftrace_syscall_print_sys_getrandom(
    struct ftrace *self, struct ftrace_process *proc)
{
    if (proc->flags & STRACE_PROCESS_IN_SYSCALL) {
        if (proc->syscall_error != 0)
            ftrace_syscall_print_address(self, proc->syscall_arguments[0]);
        else
            ftrace_syscall_print_string_ex(&((sspse_opts_t){self, proc,
                proc->syscall_arguments[0], proc->syscall_retval,
                STRACE_SYSCALL_PRINT_QUOTE_FORCE_HEX}));
        ftrace_syscall_print_next_argument(self);
        STRACE_SYSCALL_PRINT_UNSIGNED(self, proc->syscall_arguments[1]);
        ftrace_syscall_print_next_argument(self);
        ftrace_syscall_print_flags(
            self, &FLAGS_ENUM, proc->syscall_arguments[2], "GRND_???");
    }
    return (0);
}
