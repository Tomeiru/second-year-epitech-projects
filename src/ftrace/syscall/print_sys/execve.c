/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines execve
*/

#include "../entries.h"
#include "../../print_error_message.h"
#include "do_execve.h"

int ftrace_syscall_print_sys_execve(
    struct ftrace *self, struct ftrace_process *proc)
{
    ftrace_syscall_print_sys_do_execve(self, proc, 0);
    return (STRACE_SYSCALL_RETVAL_DECODED);
}
