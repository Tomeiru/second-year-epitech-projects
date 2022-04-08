/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_dir_fd
*/

#include "print_dir_fd.h"
#include "print_decimal.h"
#include "../printf.h"
#include <fcntl.h>

void strace_syscall_print_dir_fd(struct strace *self, int fd)
{
    if (fd == AT_FDCWD)
        strace_printf(self, "AT_FDCWD");
    else
        STRACE_SYSCALL_PRINT_DECIMAL(self, fd);
}
