/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_address
*/

#include "print_address.h"
#include "print_hex.h"
#include "../printf.h"

void strace_syscall_print_address(struct strace *self, uint64_t address)
{
    if (address == 0)
        strace_printf(self, "NULL");
    else
        STRACE_SYSCALL_PRINT_HEX(self, address);
}
