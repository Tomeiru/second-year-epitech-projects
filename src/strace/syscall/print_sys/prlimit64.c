/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines prlimit64
*/

#include "../entries.h"
#include "../print_decimal.h"
#include "../print_next_argument.h"
#include "../print_enum_value.h"
#include "../print_rlimit.h"
#include <sys/resource.h>

static const struct strace_enum_data RLIMIT_ENUM_DATA[] = {
    {RLIMIT_CPU, "RLIMIT_CPU"},
    {RLIMIT_FSIZE, "RLIMIT_FSIZE"},
    {RLIMIT_DATA, "RLIMIT_DATA"},
    {RLIMIT_STACK, "RLIMIT_STACK"},
    {RLIMIT_CORE, "RLIMIT_CORE"},
    {RLIMIT_RSS, "RLIMIT_RSS"},
    {RLIMIT_NPROC, "RLIMIT_NPROC"},
    {RLIMIT_NOFILE, "RLIMIT_NOFILE"},
    {RLIMIT_MEMLOCK, "RLIMIT_MEMLOCK"},
    {RLIMIT_AS, "RLIMIT_AS"},
    {RLIMIT_LOCKS, "RLIMIT_LOCKS"},
    {RLIMIT_SIGPENDING, "RLIMIT_SIGPENDING"},
    {RLIMIT_MSGQUEUE, "RLIMIT_MSGQUEUE"},
    {RLIMIT_NICE, "RLIMIT_NICE"},
    {RLIMIT_RTPRIO, "RLIMIT_RTPRIO"},
    {RLIMIT_RTTIME, "RLIMIT_RTTIME"},
};

static const struct strace_enum RLIMIT_ENUM = {
    .data = RLIMIT_ENUM_DATA,
    .size = sizeof(RLIMIT_ENUM_DATA) / sizeof(RLIMIT_ENUM_DATA[0]),
};

int strace_syscall_print_sys_prlimit64(struct strace *self,
    struct strace_process *proc)
{
    if (!(proc->flags & STRACE_PROCESS_IN_SYSCALL)) {
        STRACE_SYSCALL_PRINT_DECIMAL(self, proc->syscall_arguments[0]);
        strace_syscall_print_next_argument(self);
        strace_syscall_print_enum_value(self, &RLIMIT_ENUM,
            proc->syscall_arguments[1], "RLIMIT_???");
        strace_syscall_print_next_argument(self);
        strace_syscall_print_rlimit(self, proc, proc->syscall_arguments[2]);
        strace_syscall_print_next_argument(self);
    } else 
        strace_syscall_print_rlimit(self, proc, proc->syscall_arguments[3]);
    return (0);
}
