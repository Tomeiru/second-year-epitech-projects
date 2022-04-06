/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines number_is_valid
*/

#include "number_is_valid.h"
#include "number_is_in_range.h"
#include "entries.h"
#include <stddef.h>

bool strace_syscall_number_is_valid(__kernel_ulong_t syscall_number)
{
    return (strace_syscall_number_is_in_range(syscall_number) &&
        STRACE_SYSCALL_ENTRIES[syscall_number].function != NULL);
}
