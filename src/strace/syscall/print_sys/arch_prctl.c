/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines arch_prctl
*/

#include "../entries.h"
#include "../print_enum_value.h"
#include "../print_next_argument.h"
#include "../print_address.h"
#include "../print_hex.h"
#include <asm/prctl.h>

static const struct strace_enum_data ARCH_PRCTL_VALS_DATA[] = {
    {ARCH_SET_GS, "ARCH_SET_GS"},
    {ARCH_SET_FS, "ARCH_SET_FS"},
    {ARCH_GET_GS, "ARCH_GET_GS"},
    {ARCH_GET_FS, "ARCH_GET_FS"},
    {ARCH_GET_CPUID, "ARCH_GET_CPUID"},
    {ARCH_SET_CPUID, "ARCH_SET_CPUID"},
    {ARCH_MAP_VDSO_X32, "ARCH_SET_MAP_VDSO_X32"},
    {ARCH_MAP_VDSO_32, "ARCH_SET_MAP_VDSO_32"},
    {ARCH_MAP_VDSO_64, "ARCH_SET_MAP_VDSO_64"},
};

static const struct strace_enum ARCH_PRCTL_VALS = {
    .data = ARCH_PRCTL_VALS_DATA,
    .size = sizeof(ARCH_PRCTL_VALS_DATA) / sizeof(ARCH_PRCTL_VALS_DATA[0]),
};

int strace_syscall_print_sys_arch_prctl(
    struct strace *self, struct strace_process *proc)
{
    const unsigned option = proc->syscall_arguments[0];
    const __kernel_ulong_t address = proc->syscall_arguments[1];

    if (!(proc->flags & STRACE_PROCESS_IN_SYSCALL))
        strace_syscall_print_enum_value(
            self, &ARCH_PRCTL_VALS, option, "ARCH_???");
    switch (option) {
    case ARCH_GET_FS:
    case ARCH_GET_GS:
        if (!(proc->flags & STRACE_PROCESS_IN_SYSCALL))
            strace_syscall_print_next_argument(self);
        else
            strace_syscall_print_address(self, address);
        return (0);
    case ARCH_GET_CPUID:
        return (STRACE_SYSCALL_RETVAL_DECODED);
    }
    strace_syscall_print_next_argument(self);
    STRACE_SYSCALL_PRINT_HEX(self, address);
    return (STRACE_SYSCALL_RETVAL_DECODED);
}
