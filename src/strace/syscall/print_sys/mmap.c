/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines mmap
*/

#include "../entries.h"
#include "../print_address.h"
#include "../print_next_argument.h"
#include "../print_unsigned.h"
#include "../print_flags.h"
#include "../print_decimal.h"
#include "../print_hex.h"
#include "../enum_prot.h"
#include <sys/mman.h>

static const struct strace_enum_data FLAGS_ENUM_DATA[] = {
    {MAP_SHARED, "MAP_SHARED"},
    {MAP_PRIVATE, "MAP_PRIVATE"},
    {MAP_SHARED_VALIDATE, "MAP_SHARED_VALIDATE"},
    {MAP_FIXED, "MAP_FIXED"},
    {MAP_ANONYMOUS, "MAP_ANONYMOUS"},
    {MAP_32BIT, "MAP_32BIT"},
    {MAP_NORESERVE, "MAP_NORESERVE"},
    {MAP_POPULATE, "MAP_POPULATE"},
    {MAP_NONBLOCK, "MAP_NONBLOCK"},
    {MAP_GROWSDOWN, "MAP_GROWSDOWN"},
    {MAP_DENYWRITE, "MAP_DENYWRITE"},
    {MAP_EXECUTABLE, "MAP_EXECUTABLE"},
    {MAP_FILE, "MAP_FILE"},
    {MAP_LOCKED, "MAP_LOCKED"},
    {MAP_STACK, "MAP_STACK"},
    {MAP_HUGETLB, "MAP_HUGETLB"},
    {MAP_SYNC, "MAP_SYNC"},
    {MAP_FIXED_NOREPLACE, "MAP_FIXED_NOREPLACE"},
};

static const struct strace_enum FLAGS_ENUM = {
    .data = FLAGS_ENUM_DATA,
    .size = sizeof(FLAGS_ENUM_DATA) / sizeof(FLAGS_ENUM_DATA[0]),
};

static void print_flags(struct strace *self, __kernel_ulong_t flags)
{
    unsigned huget_val;

    strace_syscall_print_flags(self, &FLAGS_ENUM, flags & MAP_TYPE, "MAP_???");
    flags &= ~MAP_TYPE;
    huget_val = flags & ((uintmax_t)MAP_HUGE_MASK << MAP_HUGE_SHIFT);
    flags &= ~((uintmax_t)MAP_HUGE_MASK << MAP_HUGE_SHIFT);
    if (flags) {
        strace_printf(self, "|");
        strace_syscall_print_flags(self, &FLAGS_ENUM, flags, NULL);
    }
    if (huget_val != 0)
        strace_printf(self, "|%u<<MAP_HUGE_SHIFT", huget_val >> MAP_HUGE_SHIFT);
}

int strace_syscall_print_sys_mmap(struct strace *self,
    struct strace_process *proc)
{
    strace_syscall_print_address(self, proc->syscall_arguments[0]);
    strace_syscall_print_next_argument(self);
    STRACE_SYSCALL_PRINT_UNSIGNED(self, proc->syscall_arguments[1]);
    strace_syscall_print_next_argument(self);
    strace_syscall_print_flags(self, &STRACE_SYSCALL_ENUM_PROT,
        proc->syscall_arguments[2], "PROT_???");
    strace_syscall_print_next_argument(self);
    print_flags(self, proc->syscall_arguments[3]);
    strace_syscall_print_next_argument(self);
    STRACE_SYSCALL_PRINT_DECIMAL(self, (int)proc->syscall_arguments[4]);
    strace_syscall_print_next_argument(self);
    STRACE_SYSCALL_PRINT_HEX(self, proc->syscall_arguments[5]);
    return (STRACE_SYSCALL_RETVAL_DECODED | STRACE_SYSCALL_RETVAL_HEX);
}
