/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares strace
*/

#pragma once

#include <signal.h>
#include <sys/user.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <linux/posix_types.h>
#include <stdint.h>
#include <stdbool.h>
#include "basic_defs.h"

struct strace;
struct strace_process;

union strace_long_innards {
    long value;
    char innards[sizeof(long)];
};

enum strace_hex_string_style {
    STRACE_HEX_STRING_NONE,
    STRACE_HEX_STRING_ALL,
};

enum strace_syscall_print_quote_style {
    STRACE_SYSCALL_PRINT_QUOTE_0_TERM = 0x1,
    STRACE_SYSCALL_PRINT_QUOTE_HEX_STRING = 0x80,
    STRACE_SYSCALL_PRINT_QUOTE_HEX_STRING_SHIFT = 8,
    STRACE_SYSCALL_PRINT_QUOTE_HEX_STRING_MASK = 3 <<
        STRACE_SYSCALL_PRINT_QUOTE_HEX_STRING_SHIFT,
    STRACE_SYSCALL_PRINT_QUOTE_HEX_STRING_ALL = STRACE_HEX_STRING_ALL <<
        STRACE_SYSCALL_PRINT_QUOTE_HEX_STRING_SHIFT,
    STRACE_SYSCALL_PRINT_QUOTE_FORCE_HEX =
        STRACE_SYSCALL_PRINT_QUOTE_HEX_STRING |
        STRACE_SYSCALL_PRINT_QUOTE_HEX_STRING_ALL,
};

struct strace_list_item {
    struct strace_list_item *prev;
    struct strace_list_item *next;
};

enum strace_process_flags {
    STRACE_PROCESS_NO_DETACH_FIRST_EXEC = 0x1,
    STRACE_PROCESS_ATTACHED = 0x2,
    STRACE_PROCESS_BEFORE_FIRST_STOP = 0x4,
    STRACE_PROCESS_GRABBED = 0x8,
    STRACE_PROCESS_IN_SYSCALL = 0x10,
    STRACE_PROCESS_RECOVERING = 0x20,
    STRACE_PROCESS_HIDE_LOG = 0x40,
    STRACE_PROCESS_CHECK_EXEC_SUCCESS = 0x80,
    STRACE_PROCESS_FILTERED_SYSCALL = 0x100,
};

enum strace_syscall_retval_format {
    STRACE_SYSCALL_RETVAL_UNSIGNED_DECIMAL = 0x0,
    STRACE_SYSCALL_RETVAL_HEX = 0x1,
    STRACE_SYSCALL_RETVAL_FD = 0x2,
    STRACE_SYSCALL_RETVAL_FORMAT_MASK = 0xF,
    STRACE_SYSCALL_RETVAL_DECODED = 0x40,
};

struct strace_syscall_entry {
    int (*function)(struct strace *self, struct strace_process *proc);
    int number;
    const char *name;
    unsigned num_arguments;
};

struct strace_syscall_entry_buffer {
    struct strace_syscall_entry entry;
    struct strace_process *proc;
    char buffer[sizeof("syscall_0x") + sizeof(__kernel_ulong_t) * 4];
};

enum strace_qualifier_flags {
    STRACE_QUALIFIER_RAW = 0x1,
};

struct strace_process {
    pid_t pid;
    enum strace_process_flags flags;
    struct strace_list_item event_list;
    size_t event_data_index;
    __kernel_ulong_t syscall_number;
    const struct strace_syscall_entry *syscall_entry;
    __kernel_ulong_t syscall_arguments[6];
    unsigned long syscall_error;
    __kernel_long_t syscall_retval;
    enum strace_syscall_retval_format syscall_retval_format;
    int current_column;
    enum strace_qualifier_flags qualifier_flags;
    void *private_data;
    void (*private_data_free_func_ptr)(void *);
};

struct strace_process_params {
    char *exec_pathname;
    char **argv;
    struct sigaction sigchld_sigaction;
};

enum strace_event_type {
    STRACE_EVENT_BREAK_MAIN_LOOP,
    STRACE_EVENT_SIGNALLED,
    STRACE_EVENT_EXITED,
    STRACE_EVENT_SINGLESTEP_STOPPED,
    STRACE_EVENT_SIGNAL_DELIVERY_STOPPED,
    STRACE_EVENT_SIGNAL_GROUP_STOPPED,
    STRACE_EVENT_RESTART,
    STRACE_EVENT_BEFORE_EXECVE_STOPPED,
    STRACE_EVENT_BEFORE_EXIT_STOPPED,
    STRACE_EVENT_NEXT,
};

struct strace_event_data {
    int wait_status;
    enum strace_event_type type;
    siginfo_t signal_info;
    unsigned long message;
};

struct strace_enum_data {
    uintmax_t value;
    const char *string;
};

struct strace_enum {
    const struct strace_enum_data *data;
    size_t size;
};

struct strace {
    bool print_raw_arguments;
    const char *program_invocation_name;
    bool is_fd_placeholder[2];
    int exit_status;
    size_t event_table_size;
    struct strace_event_data *event_table;
    struct strace_process *current_process;
    struct strace_process *printing_process;
    pid_t tracer_pid;
    pid_t child_pid;
    uid_t traced_process_uid;
    bool has_traced_process;
    struct strace_process traced_process;
    struct strace_process_params traced_process_params;
    size_t gne_extra_index;
    struct strace_process *gne_extra_proc;
    struct strace_list_item gne_pending_procs;
    struct iovec x86_io;
    struct user_regs_struct x86_regs;
};
