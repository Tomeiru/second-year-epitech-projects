/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_comment_begin
*/

#include "print_comment_begin.h"
#include "../printf.h"

void ftrace_syscall_print_comment_begin(struct ftrace *self)
{
    ftrace_printf(self, " /* ");
}
