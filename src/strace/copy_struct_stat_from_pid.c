/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines copy_struct_stat_from_pid
*/

#include "copy_struct_stat_from_pid.h"
#include "syscall/copy_mem_or_print_address.h"

bool strace_copy_struct_stat_from_pid(struct strace *self,
    struct strace_process *proc, __kernel_ulong_t address,
    struct stat *stat_buffer)
{
    return (!strace_syscall_copy_mem_or_print_address(&((sscmopa_opts_t){
        self, proc, address, sizeof(*stat_buffer), stat_buffer })));
}
