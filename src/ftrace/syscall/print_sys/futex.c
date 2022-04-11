/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines futex
*/

#include "../entries.h"
#include "../print_address.h"
#include "../print_next_argument.h"
#include "../print_enum_value.h"
#include "../print_unsigned.h"
#include "../print_hex.h"
#include <linux/futex.h>

static const struct ftrace_enum_data FUTEX_ENUM_DATA[] = {
    {FUTEX_WAIT, "FUTEX_WAIT"},
    {FUTEX_WAKE, "FUTEX_WAKE"},
    {FUTEX_FD, "FUTEX_FD"},
    {FUTEX_REQUEUE, "FUTEX_REQUEUE"},
    {FUTEX_CMP_REQUEUE, "FUTEX_CMP_REQUEUE"},
    {FUTEX_WAKE_OP, "FUTEX_WAKE_OP"},
    {FUTEX_LOCK_PI, "FUTEX_LOCK_PI"},
    {FUTEX_UNLOCK_PI, "FUTEX_UNLOCK_PI"},
    {FUTEX_TRYLOCK_PI, "FUTEX_TRYLOCK_PI"},
    {FUTEX_WAIT_BITSET, "FUTEX_WAIT_BITSET"},
    {FUTEX_WAKE_BITSET, "FUTEX_WAKE_BITSET"},
    {FUTEX_WAIT_REQUEUE_PI, "FUTEX_WAIT_REQUEUE_PI"},
    {FUTEX_CMP_REQUEUE_PI, "FUTEX_CMP_REQUEUE_PI"},
    {FUTEX_LOCK_PI2, "FUTEX_LOCK_PI2"},
    {FUTEX_WAIT_PRIVATE, "FUTEX_WAIT_PRIVATE"},
    {FUTEX_WAKE_PRIVATE, "FUTEX_WAKE_PRIVATE"},
    {FUTEX_FD|FUTEX_PRIVATE_FLAG, "FUTEX_FD|FUTEX_PRIVATE_FLAG"},
    {FUTEX_REQUEUE_PRIVATE, "FUTEX_REQUEUE_PRIVATE"},
    {FUTEX_CMP_REQUEUE_PRIVATE, "FUTEX_CMP_REQUEUE_PRIVATE"},
    {FUTEX_WAKE_OP_PRIVATE, "FUTEX_WAKE_OP_PRIVATE"},
    {FUTEX_LOCK_PI_PRIVATE, "FUTEX_LOCK_PI_PRIVATE"},
    {FUTEX_UNLOCK_PI_PRIVATE, "FUTEX_UNLOCK_PI_PRIVATE"},
    {FUTEX_TRYLOCK_PI_PRIVATE, "FUTEX_TRYLOCK_PI_PRIVATE"},
    {FUTEX_WAIT_BITSET_PRIVATE, "FUTEX_WAIT_BITSET_PRIVATE"},
    {FUTEX_WAKE_BITSET_PRIVATE, "FUTEX_WAIT_BITSET_PRIVATE"},
    {FUTEX_WAIT_REQUEUE_PI_PRIVATE, "FUTEX_WAIT_REQUEUE_PI_PRIVATE"},
    {FUTEX_CMP_REQUEUE_PI_PRIVATE, "FUTEX_CMP_REQUEUE_PI_PRIVATE"},
    {FUTEX_LOCK_PI2_PRIVATE, "FUTEX_LOCK_PI2_PRIVATE"},
    {FUTEX_WAIT|FUTEX_CLOCK_REALTIME, "FUTEX_WAIT|FUTEX_CLOCK_REALTIME"},
    {FUTEX_WAIT_PRIVATE|FUTEX_CLOCK_REALTIME,
        "FUTEX_WAIT_PRIVATE|FUTEX_CLOCK_REALTIME"},
    {FUTEX_WAIT_BITSET|FUTEX_CLOCK_REALTIME,
        "FUTEX_WAIT_BITSET|FUTEX_CLOCK_REALTIME"},
    {FUTEX_WAIT_BITSET_PRIVATE|FUTEX_CLOCK_REALTIME,
        "FUTEX_WAIT_BITSET_PRIVATE|FUTEX_CLOCK_REALTIME"},
    {FUTEX_WAIT_REQUEUE_PI|FUTEX_CLOCK_REALTIME,
        "FUTEX_WAIT_REQUEUE_PI|FUTEX_CLOCK_REALTIME"},
    {FUTEX_WAIT_REQUEUE_PI_PRIVATE|FUTEX_CLOCK_REALTIME,
        "FUTEX_WAIT_REQUEUE_PI_PRIVATE|FUTEX_CLOCK_REALTIME"},
};

static const struct ftrace_enum FUTEX_ENUM = {
    .data = FUTEX_ENUM_DATA,
    .size = sizeof(FUTEX_ENUM_DATA) / sizeof(FUTEX_ENUM_DATA[0]),
};

static void do_commands_part2(
    struct ftrace *self, struct ftrace_process *proc, int command)
{
    if (command == FUTEX_CMP_REQUEUE || command == FUTEX_CMP_REQUEUE_PI) {
        ftrace_syscall_print_next_argument(self);
        STRACE_SYSCALL_PRINT_UNSIGNED(self, proc->syscall_arguments[2]);
        ftrace_syscall_print_next_argument(self);
        STRACE_SYSCALL_PRINT_UNSIGNED(self, proc->syscall_arguments[3]);
        ftrace_syscall_print_next_argument(self);
        ftrace_syscall_print_address(self, proc->syscall_arguments[4]);
        ftrace_syscall_print_next_argument(self);
        STRACE_SYSCALL_PRINT_UNSIGNED(self, proc->syscall_arguments[5]);
        return;
    }
    ftrace_syscall_print_next_argument(self);
    STRACE_SYSCALL_PRINT_UNSIGNED(self, proc->syscall_arguments[2]);
    ftrace_syscall_print_next_argument(self);
    ftrace_syscall_print_address(self, proc->syscall_arguments[3]);
    ftrace_syscall_print_next_argument(self);
    ftrace_syscall_print_address(self, proc->syscall_arguments[4]);
    ftrace_syscall_print_next_argument(self);
    STRACE_SYSCALL_PRINT_HEX(self, proc->syscall_arguments[5]);
}

static void do_commands(
    struct ftrace *self, struct ftrace_process *proc, int command)
{
    if (command == FUTEX_REQUEUE) {
        ftrace_syscall_print_next_argument(self);
        STRACE_SYSCALL_PRINT_UNSIGNED(self, proc->syscall_arguments[2]);
        ftrace_syscall_print_next_argument(self);
        STRACE_SYSCALL_PRINT_UNSIGNED(self, proc->syscall_arguments[3]);
        ftrace_syscall_print_next_argument(self);
        ftrace_syscall_print_address(self, proc->syscall_arguments[4]);
        return;
    }
    if (command == FUTEX_FD || command == FUTEX_WAKE) {
        ftrace_syscall_print_next_argument(self);
        STRACE_SYSCALL_PRINT_UNSIGNED(self, proc->syscall_arguments[2]);
        return;
    }
    if (command == FUTEX_UNLOCK_PI || command == FUTEX_TRYLOCK_PI)
        return;
    return (do_commands_part2(self, proc, command));
}

int ftrace_syscall_print_sys_futex(
    struct ftrace *self, struct ftrace_process *proc)
{
    ftrace_syscall_print_address(self, proc->syscall_arguments[0]);
    ftrace_syscall_print_next_argument(self);
    ftrace_syscall_print_enum_value(
        self, &FUTEX_ENUM, proc->syscall_arguments[1], "FUTEX_???");
    do_commands(self, proc, proc->syscall_arguments[1] & 127);
    return (STRACE_SYSCALL_RETVAL_DECODED);
}
