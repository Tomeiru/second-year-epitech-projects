/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_symbolic_mode_t
*/

#include "print_symbolic_mode_t.h"
#include "print_octal_03.h"
#include "../enum_lookup.h"
#include "../printf.h"
#include <sys/stat.h>
#include <stddef.h>

static const struct ftrace_enum_data IFMT_ENUM_DATA[] = {
    {S_IFREG, "S_IFREG"},
    {S_IFSOCK, "S_IFSOCK"},
    {S_IFIFO, "S_IFIFO"},
    {S_IFLNK, "S_IFLNK"},
    {S_IFDIR, "S_IFDIR"},
    {S_IFBLK, "S_IFBLK"},
    {S_IFCHR, "S_IFCHR"},
};

static const struct ftrace_enum IFMT_ENUM = {
    .data = IFMT_ENUM_DATA,
    .size = sizeof(IFMT_ENUM_DATA) / sizeof(IFMT_ENUM_DATA[0]),
};

void ftrace_syscall_print_symbolic_mode_t(struct ftrace *self, mode_t mode)
{
    const char *ifmt_string = "";

    if (mode & S_IFMT)
        ifmt_string = ftrace_enum_lookup(&IFMT_ENUM, mode & S_IFMT);
    if (ifmt_string == NULL) {
        STRACE_SYSCALL_PRINT_OCTAL_03(self, mode);
        return;
    }
    ftrace_printf(self, "%s%s%s%s%s%#03o", ifmt_string,
        ifmt_string[0] != '\0' ? "|" : "", (mode & S_ISUID) ? "S_ISUID|" : "",
        (mode & S_ISGID) ? "S_ISGID|" : "", (mode & S_ISVTX) ? "S_ISVTX|" : "",
        mode & ~(S_IFMT | S_ISUID | S_ISGID | S_ISVTX));
}
