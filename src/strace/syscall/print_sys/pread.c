/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines pread
*/

#include "../entries.h"
#include "../print_decimal.h"
#include "../print_next_argument.h"
#include "../print_address.h"
#include "../print_string_n.h"
#include "../print_unsigned.h"

int strace_syscall_print_sys_pread(struct strace *self,
    struct strace_process *proc)
{
    if (!(proc->flags & STRACE_PROCESS_IN_SYSCALL)) {
        STRACE_SYSCALL_PRINT_DECIMAL(self, proc->syscall_arguments[0]);
        strace_syscall_print_next_argument(self);
    } else {
        if (proc->syscall_error != 0)
            strace_syscall_print_address(self, proc->syscall_arguments[1]);
        else
            strace_syscall_print_string_n(self, proc,
                proc->syscall_arguments[1], proc->syscall_retval);
        strace_syscall_print_next_argument(self);
        STRACE_SYSCALL_PRINT_UNSIGNED(self, proc->syscall_arguments[2]);
        strace_syscall_print_next_argument(self);
        STRACE_SYSCALL_PRINT_DECIMAL(self, proc->syscall_arguments[3]);
    }
    return (0);
}
