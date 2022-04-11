/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_umode_t
*/

#include "print_umode_t.h"
#include "print_octal_03.h"

void ftrace_syscall_print_umode_t(struct ftrace *self, uint16_t mode)
{
    STRACE_SYSCALL_PRINT_OCTAL_03(self, mode);
}
