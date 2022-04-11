/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines do_struct_stat
*/

#include "do_struct_stat.h"
#include "../copy_struct_stat_from_pid.h"
#include "print_struct_stat.h"
#include <sys/stat.h>

void ftrace_syscall_do_struct_stat(
    struct ftrace *self, struct ftrace_process *proc, __kernel_ulong_t address)
{
    struct stat stat_buffer;

    if (ftrace_copy_struct_stat_from_pid(self, proc, address, &stat_buffer))
        ftrace_syscall_print_struct_stat(self, proc, &stat_buffer);
}
