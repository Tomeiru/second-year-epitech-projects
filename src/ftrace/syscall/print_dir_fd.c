/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_dir_fd
*/

#include "print_dir_fd.h"
#include "print_decimal.h"
#include "../printf.h"
#include <fcntl.h>

void ftrace_syscall_print_dir_fd(struct ftrace *self, int fd)
{
    if (fd == AT_FDCWD)
        ftrace_printf(self, "AT_FDCWD");
    else
        STRACE_SYSCALL_PRINT_DECIMAL(self, fd);
}
