/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines standard_fds_check_open
*/

#include "check_open.h"
#include "../fd/open_dummy.h"
#include <unistd.h>

void ftrace_standard_fds_check_open(struct ftrace *self)
{
    int fd;

    while (true) {
        fd = ftrace_fd_open_dummy(self);
        if (fd > 2)
            break;
        self->is_fd_placeholder[fd] = true;
    }
    if (fd > 2)
        close(fd);
}
