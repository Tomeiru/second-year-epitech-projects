/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines execve
*/

#include "../entries.h"
#include "../../print_error_message.h"
#include "do_execve.h"

int strace_syscall_print_sys_execve(struct strace *self,
    struct strace_process *proc)
{
    strace_syscall_print_sys_do_execve(self, proc, 0);
    return (STRACE_SYSCALL_RETVAL_DECODED);
}
