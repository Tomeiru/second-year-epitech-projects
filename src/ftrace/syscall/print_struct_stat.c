/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_struct_stat
*/

#include "print_struct_stat.h"
#include "print_more_data_after_this.h"
#include "print_struct_start.h"
#include "print_struct_next.h"
#include "print_struct_end.h"
#include "print_symbolic_mode_t.h"
#include "print_unsigned.h"
#include "print_dev_t.h"
#include "print_hex.h"
#include "../printf.h"

void ftrace_syscall_print_struct_stat(struct ftrace *self,
    struct ftrace_process *proc, const struct stat *stat_buffer)
{
    (void)proc;
    ftrace_syscall_print_struct_start(self);
    ftrace_printf(self, "st_mode=");
    ftrace_syscall_print_symbolic_mode_t(self, stat_buffer->st_mode);
    ftrace_syscall_print_struct_next(self);
    switch (stat_buffer->st_mode & S_IFMT) {
    case S_IFCHR:
    case S_IFBLK:
        ftrace_printf(self, "st_rdev=");
        STRACE_SYSCALL_PRINT_HEX(self, stat_buffer->st_rdev);
        break;
    default:
        ftrace_printf(self, "st_size=");
        STRACE_SYSCALL_PRINT_UNSIGNED(self, stat_buffer->st_size);
        break;
    }
    ftrace_syscall_print_struct_next(self);
    ftrace_syscall_print_more_data_after_this(self);
    ftrace_syscall_print_struct_end(self);
}
