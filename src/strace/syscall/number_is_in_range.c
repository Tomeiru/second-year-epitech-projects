/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines number_is_in_range
*/

#include "number_is_in_range.h"
#include "entries.h"

bool strace_syscall_number_is_in_range(__kernel_ulong_t syscall_number)
{
    return (syscall_number < STRACE_SYSCALL_ENTRIES_COUNT);
}
