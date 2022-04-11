/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines fd_open_dummy
*/

#include "open_dummy.h"
#include "set_cloexec.h"
#include "../print_error_message/errno_and_die.h"
#include <unistd.h>

int ftrace_fd_open_dummy(struct ftrace *self)
{
    int pipe_fds[2];

    if (pipe(pipe_fds) != 0)
        ftrace_print_error_message_errno_and_die(self, "pipe");
    close(pipe_fds[1]);
    ftrace_fd_set_cloexec(self, pipe_fds[0]);
    return (pipe_fds[0]);
}
