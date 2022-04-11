/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines save_errno_kill
*/

#include "save_errno_kill.h"
#include <errno.h>

int ftrace_save_errno_kill(pid_t pid, int signal)
{
    int tmp_errno = errno;
    int result = kill(pid, signal);

    errno = tmp_errno;
    return (result);
}
