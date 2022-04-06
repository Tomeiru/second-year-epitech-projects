/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_comment_end
*/

#include "print_comment_end.h"
#include "../printf.h"

void strace_syscall_print_comment_end(struct strace *self)
{
    strace_printf(self, " */");
}
