/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines fd_open_dummy
*/

#include "open_dummy.h"
#include "set_cloexec.h"
#include "../print_error_message/errno_and_die.h"
#include <unistd.h>

int strace_fd_open_dummy(struct strace *self)
{
    int pipe_fds[2];

    if (pipe(pipe_fds) != 0)
        strace_print_error_message_errno_and_die(self, "pipe");
    close(pipe_fds[1]);
    strace_fd_set_cloexec(self, pipe_fds[0]);
    return (pipe_fds[0]);
}
