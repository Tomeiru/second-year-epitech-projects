/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines standard_fds_check_open
*/

#include "check_open.h"
#include "../fd/open_dummy.h"
#include <unistd.h>

void strace_standard_fds_check_open(struct strace *self)
{
    int fd;

    while (true) {
        fd = strace_fd_open_dummy(self);
        if (fd > 2)
            break;
        self->is_fd_placeholder[fd] = true;
    }
    if (fd > 2)
        close(fd);
}
