/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines mprotect
*/

#include "../entries.h"
#include "../print_address.h"
#include "../print_next_argument.h"
#include "../print_unsigned.h"
#include "../print_flags.h"
#include "../enum_prot.h"

int ftrace_syscall_print_sys_mprotect(
    struct ftrace *self, struct ftrace_process *proc)
{
    ftrace_syscall_print_address(self, proc->syscall_arguments[0]);
    ftrace_syscall_print_next_argument(self);
    STRACE_SYSCALL_PRINT_UNSIGNED(self, proc->syscall_arguments[1]);
    ftrace_syscall_print_next_argument(self);
    ftrace_syscall_print_flags(self, &STRACE_SYSCALL_ENUM_PROT,
        proc->syscall_arguments[2], "PROT_???");
    return (STRACE_SYSCALL_RETVAL_DECODED);
}
