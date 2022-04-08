/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines openat
*/

#include "../entries.h"
#include "../print_dir_fd.h"
#include "../print_next_argument.h"
#include "../print_path.h"
#include "../print_umode_t.h"
#include "../../enum_lookup.h"
#include "../../printf.h"
#include "../../sprint_flags.h"
#include <string.h>
#include <fcntl.h>

static const struct strace_enum_data OPEN_ACCESS_ENUM_DATA[] = {
    {O_RDONLY, "O_RDONLY"},
    {O_WRONLY, "O_WRONLY"},
    {O_RDWR, "O_RDWR"},
    {O_ACCMODE, "O_ACCMODE"},
};

static const struct strace_enum OPEN_ACCESS_ENUM = {
    .data = OPEN_ACCESS_ENUM_DATA,
    .size = sizeof(OPEN_ACCESS_ENUM_DATA) / sizeof(OPEN_ACCESS_ENUM_DATA[0]),
};

static const struct strace_enum_data OPEN_MODE_ENUM_DATA[] = {
    {O_CREAT, "O_CREAT"},
    {O_EXCL, "O_EXCL"},
    {O_NOCTTY, "O_NOCTTY"},
    {O_TRUNC, "O_TRUNC"},
    {O_APPEND, "O_APPEND"},
    {O_NONBLOCK, "O_NONBLOCK"},
    {O_SYNC, "O_SYNC"},
    {O_DSYNC, "O_DSYNC"},
    {O_DIRECT, "O_DIRECT"},
    {O_LARGEFILE, "O_LARGEFILE"},
    {O_NOFOLLOW, "O_NOFOLLOW"},
    {O_NOATIME, "O_NOATIME"},
    {O_CLOEXEC, "O_CLOEXEC"},
    {O_PATH, "O_PATH"},
    {O_TMPFILE, "O_TMPFILE"},
    {O_DIRECTORY, "O_DIRECTORY"},
    {FASYNC, "FASYNC"},
};

static const struct strace_enum OPEN_MODE_ENUM = {
    .data = OPEN_MODE_ENUM_DATA,
    .size = sizeof(OPEN_MODE_ENUM_DATA) / sizeof(OPEN_MODE_ENUM_DATA[0]),
};

static const char *do_mode(struct strace *self, unsigned flags)
{
    static char output_string[sizeof("O_XXXXXXXXXXXXX") * 2];
    char separator = '\0';
    char *s = output_string;
    const char *string = strace_enum_lookup(&OPEN_ACCESS_ENUM, flags & 3);

    if (string != NULL) {
        s = stpcpy(s, string);
        flags &= ~O_ACCMODE;
        if (flags == 0)
            return (output_string);
        separator = '|';
    }
    *s = '\0';
    return (strace_sprint_flags(&((ssf_opts_t){self, output_string,
        &OPEN_MODE_ENUM, flags, separator})) ?: output_string);
}

int strace_syscall_print_sys_openat(
    struct strace *self, struct strace_process *proc)
{
    strace_syscall_print_dir_fd(self, proc->syscall_arguments[0]);
    strace_syscall_print_next_argument(self);
    strace_syscall_print_path(self, proc, proc->syscall_arguments[1]);
    strace_syscall_print_next_argument(self);
    strace_printf(self, "%s", do_mode(self, proc->syscall_arguments[2]));
    if (proc->syscall_arguments[2] & (O_CREAT | __O_TMPFILE)) {
        strace_syscall_print_next_argument(self);
        strace_syscall_print_umode_t(self, proc->syscall_arguments[3]);
    }
    return (STRACE_SYSCALL_RETVAL_DECODED | STRACE_SYSCALL_RETVAL_FD);
}
