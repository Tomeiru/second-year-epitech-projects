/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_comment_end
*/

#include "print_comment_end.h"
#include "../printf.h"

void ftrace_syscall_print_comment_end(struct ftrace *self)
{
    ftrace_printf(self, " */");
}
