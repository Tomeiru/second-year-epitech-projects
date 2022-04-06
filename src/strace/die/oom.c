/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines die_oom
*/

#include "oom.h"
#include "../print_error_message/and_die.h"
#include <stdlib.h>

void strace_die_oom(struct strace *self)
{
    static int have_already_been_here = 0;

    if (have_already_been_here > 1)
        _Exit(1);
    if (have_already_been_here == 1)
        exit(1);
    ++have_already_been_here;
    strace_print_error_message_and_die(self, "Out of memory");
}
