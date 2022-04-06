/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines execve
*/

#include "../entries.h"
#include "../../print_error_message.h"

int strace_syscall_print_sys_execve(struct strace *self,
    struct strace_process *proc)
{
    strace_print_error_message(self, "TODO: implement execve properly");
    return (strace_syscall_print_raw_arguments(self, proc));
}
