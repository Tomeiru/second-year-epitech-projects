/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares ftrace
*/

#pragma once

#include "my/ftrace_mmap_entry_vector_part4.h"
#include <gelf.h>
#include <libelf.h>
#include <signal.h>
#include <sys/user.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <linux/posix_types.h>
#include <stdint.h>
#include <stdbool.h>
#include "basic_defs.h"
#include "my/ftrace_symbol_vector.h"
#include "my/ftrace_mmap_entry_vector.h"

struct ftrace;
struct ftrace_process;

union ftrace_long_innards {
    long value;
    char innards[sizeof(long)];
};

struct ftrace_list_item {
    struct ftrace_list_item *prev;
    struct ftrace_list_item *next;
};

enum ftrace_process_flags {
    STRACE_PROCESS_NO_DETACH_FIRST_EXEC = 0x1,
    STRACE_PROCESS_ATTACHED = 0x2,
    STRACE_PROCESS_BEFORE_FIRST_STOP = 0x4,
    STRACE_PROCESS_GRABBED = 0x8,
    STRACE_PROCESS_IN_SYSCALL = 0x10,
    STRACE_PROCESS_RECOVERING = 0x20,
    STRACE_PROCESS_HIDE_LOG = 0x40,
    STRACE_PROCESS_CHECK_EXEC_SUCCESS = 0x80,
    STRACE_PROCESS_FILTERED_SYSCALL = 0x100,
    STRACE_PROCESS_IN_CALL = 0x20,
};

enum ftrace_syscall_retval_format {
    STRACE_SYSCALL_RETVAL_DECODED = 0x40,
};

enum ftrace_syscall_entry_flags {
    STRACE_SYSCALL_ENTRY_MEMORY_MAPPING_CHANGE = 0x1,
};

struct ftrace_syscall_entry {
    int number;
    const char *name;
    unsigned num_arguments;
    int flags;
};

struct ftrace_syscall_entry_buffer {
    struct ftrace_syscall_entry entry;
    struct ftrace_process *proc;
    char buffer[sizeof("syscall_0x") + sizeof(__kernel_ulong_t) * 4];
};

enum ftrace_qualifier_flags {
    STRACE_QUALIFIER_RAW = 0x1,
};

struct ftrace_process {
    pid_t pid;
    enum ftrace_process_flags flags;
    struct ftrace_list_item event_list;
    size_t event_data_index;
    __kernel_ulong_t syscall_number;
    const struct ftrace_syscall_entry *syscall_entry;
    __kernel_ulong_t syscall_arguments[6];
    unsigned long syscall_error;
    __kernel_long_t syscall_retval;
    enum ftrace_syscall_retval_format syscall_retval_format;
    int current_column;
    enum ftrace_qualifier_flags qualifier_flags;
    void *private_data;
    void (*private_data_free_func_ptr)(void *);
    struct my_ftrace_mmap_entry_vector *mmap_entries;
    bool proc_maps_up_to_date;
    struct my_ftrace_symbol_vector *retrieved_symbols;
};

struct ftrace_process_params {
    char *exec_pathname;
    char **argv;
    struct sigaction sigchld_sigaction;
};

enum ftrace_event_type {
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

struct ftrace_event_data {
    int wait_status;
    enum ftrace_event_type type;
    siginfo_t signal_info;
    unsigned long message;
};

struct ftrace {
    const char *program_invocation_name;
    bool is_fd_placeholder[2];
    int exit_status;
    size_t event_table_size;
    struct ftrace_event_data *event_table;
    struct ftrace_process *current_process;
    struct ftrace_process *printing_process;
    pid_t tracer_pid;
    pid_t child_pid;
    uid_t traced_process_uid;
    bool has_traced_process;
    struct ftrace_process traced_process;
    struct ftrace_process_params traced_process_params;
    size_t gne_extra_index;
    struct ftrace_process *gne_extra_proc;
    struct ftrace_list_item gne_pending_procs;
    struct iovec x86_io;
    struct user_regs_struct x86_regs;
};
