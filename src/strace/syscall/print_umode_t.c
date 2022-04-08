/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_umode_t
*/

#include "print_umode_t.h"
#include "print_octal_03.h"

void strace_syscall_print_umode_t(struct strace *self, uint16_t mode)
{
    STRACE_SYSCALL_PRINT_OCTAL_03(self, mode);
}
