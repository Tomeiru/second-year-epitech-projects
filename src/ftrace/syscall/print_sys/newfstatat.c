/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines newfstatat
*/

#include "../entries.h"
#include "../print_dir_fd.h"
#include "../print_next_argument.h"
#include "../print_path.h"
#include "../print_flags.h"
#include "../do_struct_stat.h"
#include <fcntl.h>

static const struct ftrace_enum_data AT_ENUM_DATA[] = {
    {AT_SYMLINK_NOFOLLOW, "AT_SYMLINK_NO_FOLLOW"},
    {AT_REMOVEDIR, "AT_REMOVEDIR"},
    {AT_SYMLINK_FOLLOW, "AT_SYMLINK_FOLLOW"},
    {AT_NO_AUTOMOUNT, "AT_NO_AUTOMOUNT"},
    {AT_EMPTY_PATH, "AT_EMPTY_PATH"},
    {AT_RECURSIVE, "AT_RECURSIVE"},
};

static const struct ftrace_enum AT_ENUM = {
    .data = AT_ENUM_DATA,
    .size = sizeof(AT_ENUM_DATA) / sizeof(AT_ENUM_DATA[0]),
};

int ftrace_syscall_print_sys_newfstatat(
    struct ftrace *self, struct ftrace_process *proc)
{
    if (!(proc->flags & STRACE_PROCESS_IN_SYSCALL)) {
        ftrace_syscall_print_dir_fd(self, proc->syscall_arguments[0]);
        ftrace_syscall_print_next_argument(self);
        ftrace_syscall_print_path(self, proc, proc->syscall_arguments[1]);
        ftrace_syscall_print_next_argument(self);
    } else {
        ftrace_syscall_do_struct_stat(self, proc, proc->syscall_arguments[2]);
        ftrace_syscall_print_next_argument(self);
        ftrace_syscall_print_flags(
            self, &AT_ENUM, proc->syscall_arguments[3], "AT_???");
    }
    return (0);
}
