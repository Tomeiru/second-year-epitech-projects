/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines do_struct_stat
*/

#include "do_struct_stat.h"
#include "../copy_struct_stat_from_pid.h"
#include "print_struct_stat.h"
#include <sys/stat.h>

void strace_syscall_do_struct_stat(struct strace *self,
    struct strace_process *proc, __kernel_ulong_t address)
{
    struct stat stat_buffer;

    if (strace_copy_struct_stat_from_pid(self, proc, address, &stat_buffer))
        strace_syscall_print_struct_stat(self, proc, &stat_buffer);
}
