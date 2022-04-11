/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_path_n
*/

#include "print_path_n.h"
#include "print_address.h"
#include "print_quoted_c_string.h"
#include "../printf.h"
#include "../copy_str_from_pid.h"
#include <limits.h>

int ftrace_syscall_print_path_n(struct ftrace *self,
    struct ftrace_process *proc, __kernel_ulong_t address, size_t n)
{
    char pathname[PATH_MAX];
    int saw_null;

    if (address == 0) {
        ftrace_printf(self, "NULL");
        return (-1);
    }
    n = (n <= sizeof(pathname) - 1) ? n : sizeof(pathname) - 1;
    saw_null = ftrace_copy_str_from_pid(&((scsfp_opts_t){self, proc->pid,
        address, n + 1, pathname}));
    if (saw_null < 0)
        ftrace_syscall_print_address(self, address);
    else {
        pathname[n++] = saw_null == 0;
        ftrace_syscall_print_quoted_c_string(self, pathname, n);
    }
    return (saw_null);
}
