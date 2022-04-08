/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines copy_mem_from_pid
*/

#include "copy_mem_from_pid.h"
#include "print_error_message/errno.h"
#include <string.h>
#include <sys/ptrace.h>
#include <errno.h>
#include <stdint.h>

static bool check_errno(scmfp_opts_t *o, size_t num_read)
{
    if (errno == ESRCH || errno == EINVAL)
        return (false);
    if (errno == EFAULT || errno == EIO || errno == EPERM) {
        if (num_read != 0)
            strace_print_error_message_errno(o->self, "short read (%zu < %zu) "
                "@0x%jx", num_read, num_read + o->length, (intmax_t)(
                o->address - num_read));
        return (false);
    }
    if (errno != 0) {
        strace_print_error_message_errno(o->self, "pid:%jd @0x%jx",
            (intmax_t)o->pid, (intmax_t)o->address);
        return (false);
    }
    return (true);
}

static void scsfp_finish_loop(
    scmfp_opts_t *o, size_t *r, size_t x, size_t *num_read)
{
    *r = 0;
    o->address += sizeof(long);
    o->output_address += x;
    *num_read += x;
    o->length -= x;
}

int strace_copy_mem_from_pid(scmfp_opts_t *o)
{
    union strace_long_innards v;
    size_t num_read = 0;
    size_t x;
    size_t r = o->address & (sizeof(long) - 1);

    while (o->length != 0) {
        o->address &= -sizeof(long);
        errno = 0;
        v.value = ptrace(PTRACE_PEEKDATA, o->pid, o->address, 0);
        if (!check_errno(o, num_read))
            return (-1);
        x = ((sizeof(long) - r) < o->length) ? (sizeof(long) - r) : o->length;
        memcpy(o->output_address, &v.innards[r], x);
        scsfp_finish_loop(o, &r, x, &num_read);
    }
    return (0);
}
