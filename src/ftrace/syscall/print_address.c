/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_address
*/

#include "print_address.h"
#include "print_hex.h"
#include "../printf.h"

void ftrace_syscall_print_address(struct ftrace *self, uint64_t address)
{
    if (address == 0)
        ftrace_printf(self, "NULL");
    else
        STRACE_SYSCALL_PRINT_HEX(self, address);
}
