/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines die_oom
*/

#include "oom.h"
#include "../print_error_message/and_die.h"
#include <stdlib.h>

void ftrace_die_oom(struct ftrace *self)
{
    static int have_already_been_here = 0;

    if (have_already_been_here > 1)
        _Exit(1);
    if (have_already_been_here == 1)
        exit(1);
    ++have_already_been_here;
    ftrace_print_error_message_and_die(self, "Out of memory");
}
