/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines pread
*/

#include "../entries.h"
#include "../print_decimal.h"
#include "../print_next_argument.h"
#include "../print_address.h"
#include "../print_string_n.h"
#include "../print_unsigned.h"

int ftrace_syscall_print_sys_pread(
    struct ftrace *self, struct ftrace_process *proc)
{
    if (!(proc->flags & STRACE_PROCESS_IN_SYSCALL)) {
        STRACE_SYSCALL_PRINT_DECIMAL(self, proc->syscall_arguments[0]);
        ftrace_syscall_print_next_argument(self);
    } else {
        if (proc->syscall_error != 0)
            ftrace_syscall_print_address(self, proc->syscall_arguments[1]);
        else
            ftrace_syscall_print_string_n(
                self, proc, proc->syscall_arguments[1], proc->syscall_retval);
        ftrace_syscall_print_next_argument(self);
        STRACE_SYSCALL_PRINT_UNSIGNED(self, proc->syscall_arguments[2]);
        ftrace_syscall_print_next_argument(self);
        STRACE_SYSCALL_PRINT_DECIMAL(self, proc->syscall_arguments[3]);
    }
    return (0);
}
