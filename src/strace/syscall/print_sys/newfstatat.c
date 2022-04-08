/*
** EPITECH PROJECT, 2022
** strace
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

static const struct strace_enum_data AT_ENUM_DATA[] = {
    {AT_SYMLINK_NOFOLLOW, "AT_SYMLINK_NO_FOLLOW"},
    {AT_REMOVEDIR, "AT_REMOVEDIR"},
    {AT_SYMLINK_FOLLOW, "AT_SYMLINK_FOLLOW"},
    {AT_NO_AUTOMOUNT, "AT_NO_AUTOMOUNT"},
    {AT_EMPTY_PATH, "AT_EMPTY_PATH"},
    {AT_RECURSIVE, "AT_RECURSIVE"},
};

static const struct strace_enum AT_ENUM = {
    .data = AT_ENUM_DATA,
    .size = sizeof(AT_ENUM_DATA) / sizeof(AT_ENUM_DATA[0]),
};

int strace_syscall_print_sys_newfstatat(
    struct strace *self, struct strace_process *proc)
{
    if (!(proc->flags & STRACE_PROCESS_IN_SYSCALL)) {
        strace_syscall_print_dir_fd(self, proc->syscall_arguments[0]);
        strace_syscall_print_next_argument(self);
        strace_syscall_print_path(self, proc, proc->syscall_arguments[1]);
        strace_syscall_print_next_argument(self);
    } else {
        strace_syscall_do_struct_stat(self, proc, proc->syscall_arguments[2]);
        strace_syscall_print_next_argument(self);
        strace_syscall_print_flags(
            self, &AT_ENUM, proc->syscall_arguments[3], "AT_???");
    }
    return (0);
}
