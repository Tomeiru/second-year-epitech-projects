/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_comment_begin
*/

#include "print_comment_begin.h"
#include "../printf.h"

void strace_syscall_print_comment_begin(struct strace *self)
{
    strace_printf(self, " /* ");
}
