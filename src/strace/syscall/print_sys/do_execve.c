/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines do_execve
*/

#include "do_execve.h"
#include "../print_next_argument.h"
#include "../print_path.h"
#include "../print_argv.h"
#include "../print_argc.h"
#include "../../print_error_message.h"

void strace_syscall_print_sys_do_execve(
    struct strace *self, struct strace_process *proc, unsigned int args_index)
{
    strace_syscall_print_path(self, proc, proc->syscall_arguments[args_index]);
    strace_syscall_print_next_argument(self);
    strace_syscall_print_argv(
        self, proc, proc->syscall_arguments[args_index + 1]);
    strace_syscall_print_next_argument(self);
    strace_syscall_print_argc(
        self, proc, proc->syscall_arguments[args_index + 2]);
}
