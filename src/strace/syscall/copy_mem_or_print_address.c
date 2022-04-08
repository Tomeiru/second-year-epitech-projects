/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines copy_mem_or_print_address
*/

#include "copy_mem_or_print_address.h"
#include "../copy_mem_from_pid.h"
#include "print_address.h"

int strace_syscall_copy_mem_or_print_address(sscmopa_opts_t *o)
{
    if (o->address != 0 && (!(o->proc->flags & STRACE_PROCESS_IN_SYSCALL) ||
        (o->proc->syscall_error == 0)) &&
        !strace_copy_mem_from_pid(&((scmfp_opts_t){o->self, o->proc->pid,
        o->address, o->length, o->output_address})))
        return (0);
    strace_syscall_print_address(o->self, o->address);
    return (-1);
}
