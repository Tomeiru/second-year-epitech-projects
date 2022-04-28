/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines fd_set_cloexec
*/

#include "set_cloexec.h"
#include "../print_error_message/errno_and_die.h"
#include <fcntl.h>

void ftrace_fd_set_cloexec(struct ftrace *self, int fd)
{
    int old_flags = fcntl(fd, F_GETFD);
    int new_flags = old_flags | FD_CLOEXEC;

    if (old_flags < 0)
        ftrace_print_error_message_errno_and_die(self, "fcntl(%d, F_GETFD)",
            fd);
    if (new_flags != old_flags)
        if (fcntl(fd, F_SETFD, new_flags) != 0)
            ftrace_print_error_message_errno_and_die(self,
                "fcntl(%d, F_SETFD, %#x)", fd, new_flags);
}
