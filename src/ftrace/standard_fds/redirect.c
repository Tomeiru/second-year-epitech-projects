/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines standard_fds_redirect
*/

#include "redirect.h"
#include "../fd/open_dummy.h"
#include <unistd.h>

void ftrace_standard_fds_redirect(struct ftrace *self)
{
    for (int i = 0; i < 2; ++i)
        if (!self->is_fd_placeholder[i]) {
            close(i);
            ftrace_fd_open_dummy(self);
        }
}
