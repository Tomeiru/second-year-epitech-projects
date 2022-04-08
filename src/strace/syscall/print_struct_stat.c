/*
** EPITECH PROJECT, 2022
** strace
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

void strace_syscall_print_struct_stat(struct strace *self,
    struct strace_process *proc, const struct stat *stat_buffer)
{
    (void)proc;
    strace_syscall_print_struct_start(self);
    strace_printf(self, "st_mode=");
    strace_syscall_print_symbolic_mode_t(self, stat_buffer->st_mode);
    strace_syscall_print_struct_next(self);
    switch (stat_buffer->st_mode & S_IFMT) {
    case S_IFCHR:
    case S_IFBLK:
        strace_printf(self, "st_rdev=");
        STRACE_SYSCALL_PRINT_HEX(self, stat_buffer->st_rdev);
        break;
    default:
        strace_printf(self, "st_size=");
        STRACE_SYSCALL_PRINT_UNSIGNED(self, stat_buffer->st_size);
        break;
    }
    strace_syscall_print_struct_next(self);
    strace_syscall_print_more_data_after_this(self);
    strace_syscall_print_struct_end(self);
}
