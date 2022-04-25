/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares entries
*/

#pragma once

#include "../../ftrace.h"
#include "print_raw_arguments.h"
#include <sys/syscall.h>
#include <stddef.h>

int ftrace_syscall_print_arguments_decimal(
    struct ftrace *self, struct ftrace_process *proc);
int ftrace_syscall_print_sys_execve(
    struct ftrace *self, struct ftrace_process *proc);
int ftrace_syscall_print_sys_write(
    struct ftrace *self, struct ftrace_process *proc);
int ftrace_syscall_print_sys_brk(
    struct ftrace *self, struct ftrace_process *proc);
int ftrace_syscall_print_sys_arch_prctl(
    struct ftrace *self, struct ftrace_process *proc);
int ftrace_syscall_print_sys_access(
    struct ftrace *self, struct ftrace_process *proc);
int ftrace_syscall_print_sys_openat(
    struct ftrace *self, struct ftrace_process *proc);
int ftrace_syscall_print_sys_newfstatat(
    struct ftrace *self, struct ftrace_process *proc);
int ftrace_syscall_print_sys_mmap(
    struct ftrace *self, struct ftrace_process *proc);
int ftrace_syscall_print_sys_close(
    struct ftrace *self, struct ftrace_process *proc);
int ftrace_syscall_print_sys_read(
    struct ftrace *self, struct ftrace_process *proc);
int ftrace_syscall_print_sys_pread(
    struct ftrace *self, struct ftrace_process *proc);
int ftrace_syscall_print_sys_mprotect(
    struct ftrace *self, struct ftrace_process *proc);
int ftrace_syscall_print_sys_munmap(
    struct ftrace *self, struct ftrace_process *proc);
int ftrace_syscall_print_sys_prlimit64(
    struct ftrace *self, struct ftrace_process *proc);
int ftrace_syscall_print_sys_getrandom(
    struct ftrace *self, struct ftrace_process *proc);
int ftrace_syscall_print_sys_futex(
    struct ftrace *self, struct ftrace_process *proc);

static const struct ftrace_syscall_entry STRACE_SYSCALL_ENTRIES[] = {
    [SYS_execve] = {
        .number = SYS_execve,
        .name = "execve",
        .num_arguments = 3,
        .flags = STRACE_SYSCALL_ENTRY_MEMORY_MAPPING_CHANGE,
    },
    [SYS_execveat] = {
        .number = SYS_execveat,
        .name = "execveat",
        .num_arguments = 5,
        .flags = STRACE_SYSCALL_ENTRY_MEMORY_MAPPING_CHANGE,
    },
    [SYS_exit] = {
        .number = SYS_exit,
        .name = "exit",
        .num_arguments = 1,
    },
    [SYS_exit_group] = {
        .number = SYS_exit,
        .name = "exit_group",
        .num_arguments = 1,
    },
    [SYS_brk] = {
        .number = SYS_brk,
        .name = "brk",
        .num_arguments = 1,
        .flags = STRACE_SYSCALL_ENTRY_MEMORY_MAPPING_CHANGE,
    },
    [SYS_arch_prctl] = {
        .number = SYS_arch_prctl,
        .name = "arch_prctl",
        .num_arguments = 2,
    },
    [SYS_access] = {
        .number = SYS_access,
        .name = "access",
        .num_arguments = 2,
    },
    [SYS_openat] = {
        .number = SYS_openat,
        .name = "openat",
        .num_arguments = 4,
    },
    [SYS_newfstatat] = {
        .number = SYS_newfstatat,
        .name = "newfstatat",
        .num_arguments = 4,
    },
    [SYS_mmap] = {
        .number = SYS_mmap,
        .name = "mmap",
        .num_arguments = 6,
        .flags = STRACE_SYSCALL_ENTRY_MEMORY_MAPPING_CHANGE,
    },
    [SYS_close] = {
        .number = SYS_close,
        .name = "close",
        .num_arguments = 1,
    },
    [SYS_read] = {
        .number = SYS_read,
        .name = "read",
        .num_arguments = 3,
    },
    [SYS_pread64] = {
        .number = SYS_pread64,
        .name = "pread64",
        .num_arguments = 4,
    },
    [SYS_mprotect] = {
        .number = SYS_mprotect,
        .name = "mprotect",
        .num_arguments = 3,
    },
    [SYS_set_tid_address] = {
        .number = SYS_set_tid_address,
        .name = "set_tid_address",
        .num_arguments = 1,
    },
    [SYS_set_robust_list] = {
        .number = SYS_set_robust_list,
        .name = "set_robust_list",
        .num_arguments = 2,
    },
    [SYS_prlimit64] = {
        .number = SYS_prlimit64,
        .name = "prlimit64",
        .num_arguments = 4,
    },
    [SYS_munmap] = {
        .number = SYS_munmap,
        .name = "munmap",
        .num_arguments = 2,
        .flags = STRACE_SYSCALL_ENTRY_MEMORY_MAPPING_CHANGE,
    },
    [SYS_getrandom] = {
        .number = SYS_getrandom,
        .name = "getrandom",
        .num_arguments = 3,
    },
    [SYS_futex] = {
        .number = SYS_futex,
        .name = "futex",
        .num_arguments = 6,
    },
    [SYS_write] = {
        .number = SYS_write,
        .name = "write",
        .num_arguments = 3,
    },
    [SYS_ioctl] = {
        .number = SYS_ioctl,
        .name = "ioctl",
        .num_arguments = 3,
    },
    [SYS_statfs] = {
        .number = SYS_statfs,
        .name = "statfs",
        .num_arguments = 2,
    },
    [SYS_open] = {
        .number = SYS_open,
        .name = "open",
        .num_arguments = 2,
    },
    [SYS_stat] = {
        .number = SYS_stat,
        .name = "stat",
        .num_arguments = 2,
    },
    [SYS_fstat] = {
        .number = SYS_fstat,
        .name = "fstat",
        .num_arguments = 2,
    },
    [SYS_lstat] = {
        .number = SYS_lstat,
        .name = "lstat",
        .num_arguments = 2,
    },
    [SYS_poll] = {
        .number = SYS_poll,
        .name = "poll",
        .num_arguments = 3,
    },
    [SYS_lseek] = {
        .number = SYS_lseek,
        .name = "lseek",
        .num_arguments = 3,
    },
    [SYS_rt_sigaction] = {
        .number = SYS_rt_sigaction,
        .name = "rt_sigaction",
        .num_arguments = 6,
    },
    [SYS_rt_sigprocmask] = {
        .number = SYS_rt_sigprocmask,
        .name = "rt_sigprocmask",
        .num_arguments = 4,
    },
    [SYS_rt_sigreturn] = {
        .number = SYS_rt_sigreturn,
        .name = "rt_sigreturn",
        .num_arguments = 6,
    },
    [SYS_pwrite64] = {
        .number = SYS_pwrite64,
        .name = "pwrite64",
        .num_arguments = 6,
    },
    [SYS_readv] = {
        .number = SYS_readv,
        .name = "readv",
        .num_arguments = 3,
    },
    [SYS_writev] = {
        .number = SYS_writev,
        .name = "writev",
        .num_arguments = 3,
    },
    [SYS_pipe] = {
        .number = SYS_pipe,
        .name = "pipe",
        .num_arguments = 1,
    },
    [SYS_select] = {
        .number = SYS_select,
        .name = "select",
        .num_arguments = 5,
    },
    [SYS_sched_yield] = {
        .number = SYS_sched_yield,
        .name = "sched_yield",
        .num_arguments = 1,
    },
    [SYS_mremap] = {
        .number = SYS_mremap,
        .name = "mremap",
        .num_arguments = 0,
        .flags = STRACE_SYSCALL_ENTRY_MEMORY_MAPPING_CHANGE,
    },
    [SYS_msync] = {
        .number = SYS_msync,
        .name = "msync",
        .num_arguments = 3,
    },
    [SYS_mincore] = {
        .number = SYS_mincore,
        .name = "mincore",
        .num_arguments = 3,
    },
    [SYS_madvise] = {
        .number = SYS_madvise,
        .name = "madvise",
        .num_arguments = 3,
    },
    [SYS_shmget] = {
        .number = SYS_shmget,
        .name = "shmget",
        .num_arguments = 3,
    },
    [SYS_shmat] = {
        .number = SYS_shmat,
        .name = "shmat",
        .num_arguments = 3,
        .flags = STRACE_SYSCALL_ENTRY_MEMORY_MAPPING_CHANGE,
    },
    [SYS_shmctl] = {
        .number = SYS_shmctl,
        .name = "shmctl",
        .num_arguments = 3,
    },
    [SYS_dup] = {
        .number = SYS_dup,
        .name = "dup",
        .num_arguments = 1,
    },
    [SYS_dup2] = {
        .number = SYS_dup2,
        .name = "dup2",
        .num_arguments = 2,
    },
    [SYS_pause] = {
        .number = SYS_pause,
        .name = "pause",
        .num_arguments = 1,
    },
    [SYS_nanosleep] = {
        .number = SYS_nanosleep,
        .name = "nanosleep",
        .num_arguments = 2,
    },
    [SYS_getitimer] = {
        .number = SYS_getitimer,
        .name = "getitimer",
        .num_arguments = 2,
    },
    [SYS_alarm] = {
        .number = SYS_alarm,
        .name = "alarm",
        .num_arguments = 1,
    },
    [SYS_setitimer] = {
        .number = SYS_setitimer,
        .name = "setitimer",
        .num_arguments = 3,
    },
    [SYS_getpid] = {
        .number = SYS_getpid,
        .name = "getpid",
        .num_arguments = 1,
    },
    [SYS_sendfile] = {
        .number = SYS_sendfile,
        .name = "sendfile",
        .num_arguments = 4,
    },
    [SYS_socket] = {
        .number = SYS_socket,
        .name = "socket",
        .num_arguments = 3,
    },
    [SYS_connect] = {
        .number = SYS_connect,
        .name = "connect",
        .num_arguments = 3,
    },
    [SYS_accept] = {
        .number = SYS_accept,
        .name = "accept",
        .num_arguments = 3,
    },
    [SYS_sendto] = {
        .number = SYS_sendto,
        .name = "sendto",
        .num_arguments = 6,
    },
    [SYS_recvfrom] = {
        .number = SYS_recvfrom,
        .name = "recvfrom",
        .num_arguments = 6,
    },
    [SYS_sendmsg] = {
        .number = SYS_sendmsg,
        .name = "sendmsg",
        .num_arguments = 3,
    },
    [SYS_recvmsg] = {
        .number = SYS_recvmsg,
        .name = "recvmsg",
        .num_arguments = 3,
    },
    [SYS_shutdown] = {
        .number = SYS_shutdown,
        .name = "shutdown",
        .num_arguments = 2,
    },
    [SYS_bind] = {
        .number = SYS_bind,
        .name = "bind",
        .num_arguments = 3,
    },
    [SYS_listen] = {
        .number = SYS_listen,
        .name = "listen",
        .num_arguments = 2,
    },
    [SYS_getsockname] = {
        .number = SYS_getsockname,
        .name = "getsockname",
        .num_arguments = 3,
    },
    [SYS_getpeername] = {
        .number = SYS_getpeername,
        .name = "getpeername",
        .num_arguments = 3,
    },
    [SYS_socketpair] = {
        .number = SYS_socketpair,
        .name = "socketpair",
        .num_arguments = 4,
    },
    [SYS_setsockopt] = {
        .number = SYS_setsockopt,
        .name = "setsockopt",
        .num_arguments = 5,
    },
    [SYS_getsockopt] = {
        .number = SYS_getsockopt,
        .name = "getsockopt",
        .num_arguments = 5,
    },
    [SYS_clone] = {
        .number = SYS_clone,
        .name = "clone",
        .num_arguments = 0,
    },
    [SYS_fork] = {
        .number = SYS_fork,
        .name = "fork",
        .num_arguments = 1,
    },
    [SYS_vfork] = {
        .number = SYS_vfork,
        .name = "vfork",
        .num_arguments = 1,
    },
    [SYS_wait4] = {
        .number = SYS_wait4,
        .name = "wait4",
        .num_arguments = 4,
    },
    [SYS_kill] = {
        .number = SYS_kill,
        .name = "kill",
        .num_arguments = 2,
    },
    [SYS_uname] = {
        .number = SYS_uname,
        .name = "uname",
        .num_arguments = 1,
    },
    [SYS_semget] = {
        .number = SYS_semget,
        .name = "semget",
        .num_arguments = 3,
    },
    [SYS_semop] = {
        .number = SYS_semop,
        .name = "semop",
        .num_arguments = 3,
    },
    [SYS_semctl] = {
        .number = SYS_semctl,
        .name = "semctl",
        .num_arguments = 4,
    },
    [SYS_shmdt] = {
        .number = SYS_shmdt,
        .name = "shmdt",
        .num_arguments = 1,
        .flags = STRACE_SYSCALL_ENTRY_MEMORY_MAPPING_CHANGE,
    },
    [SYS_msgget] = {
        .number = SYS_msgget,
        .name = "msgget",
        .num_arguments = 2,
    },
    [SYS_msgsnd] = {
        .number = SYS_msgsnd,
        .name = "msgsnd",
        .num_arguments = 4,
    },
    [SYS_msgrcv] = {
        .number = SYS_msgrcv,
        .name = "msgrcv",
        .num_arguments = 5,
    },
    [SYS_msgctl] = {
        .number = SYS_msgctl,
        .name = "msgctl",
        .num_arguments = 3,
    },
    [SYS_fcntl] = {
        .number = SYS_fcntl,
        .name = "fcntl",
        .num_arguments = 0,
    },
    [SYS_flock] = {
        .number = SYS_flock,
        .name = "flock",
        .num_arguments = 2,
    },
    [SYS_fsync] = {
        .number = SYS_fsync,
        .name = "fsync",
        .num_arguments = 1,
    },
    [SYS_fdatasync] = {
        .number = SYS_fdatasync,
        .name = "fdatasync",
        .num_arguments = 1,
    },
    [SYS_truncate] = {
        .number = SYS_truncate,
        .name = "truncate",
        .num_arguments = 2,
    },
    [SYS_ftruncate] = {
        .number = SYS_ftruncate,
        .name = "ftruncate",
        .num_arguments = 2,
    },
    [SYS_getdents] = {
        .number = SYS_getdents,
        .name = "getdents",
        .num_arguments = 3,
    },
    [SYS_getcwd] = {
        .number = SYS_getcwd,
        .name = "getcwd",
        .num_arguments = 2,
    },
    [SYS_chdir] = {
        .number = SYS_chdir,
        .name = "chdir",
        .num_arguments = 1,
    },
    [SYS_fchdir] = {
        .number = SYS_fchdir,
        .name = "fchdir",
        .num_arguments = 1,
    },
    [SYS_rename] = {
        .number = SYS_rename,
        .name = "rename",
        .num_arguments = 2,
    },
    [SYS_mkdir] = {
        .number = SYS_mkdir,
        .name = "mkdir",
        .num_arguments = 2,
    },
    [SYS_rmdir] = {
        .number = SYS_rmdir,
        .name = "rmdir",
        .num_arguments = 1,
    },
    [SYS_creat] = {
        .number = SYS_creat,
        .name = "creat",
        .num_arguments = 2,
    },
    [SYS_link] = {
        .number = SYS_link,
        .name = "link",
        .num_arguments = 2,
    },
    [SYS_unlink] = {
        .number = SYS_unlink,
        .name = "unlink",
        .num_arguments = 1,
    },
    [SYS_symlink] = {
        .number = SYS_symlink,
        .name = "symlink",
        .num_arguments = 2,
    },
    [SYS_readlink] = {
        .number = SYS_readlink,
        .name = "readlink",
        .num_arguments = 3,
    },
    [SYS_chmod] = {
        .number = SYS_chmod,
        .name = "chmod",
        .num_arguments = 2,
    },
    [SYS_fchmod] = {
        .number = SYS_fchmod,
        .name = "fchmod",
        .num_arguments = 2,
    },
    [SYS_chown] = {
        .number = SYS_chown,
        .name = "chown",
        .num_arguments = 3,
    },
    [SYS_fchown] = {
        .number = SYS_fchown,
        .name = "fchown",
        .num_arguments = 3,
    },
    [SYS_lchown] = {
        .number = SYS_lchown,
        .name = "lchown",
        .num_arguments = 3,
    },
    [SYS_umask] = {
        .number = SYS_umask,
        .name = "umask",
        .num_arguments = 1,
    },
    [SYS_gettimeofday] = {
        .number = SYS_gettimeofday,
        .name = "gettimeofday",
        .num_arguments = 2,
    },
    [SYS_getrlimit] = {
        .number = SYS_getrlimit,
        .name = "getrlimit",
        .num_arguments = 2,
    },
    [SYS_getrusage] = {
        .number = SYS_getrusage,
        .name = "getrusage",
        .num_arguments = 2,
    },
    [SYS_sysinfo] = {
        .number = SYS_sysinfo,
        .name = "sysinfo",
        .num_arguments = 1,
    },
    [SYS_times] = {
        .number = SYS_times,
        .name = "times",
        .num_arguments = 1,
    },
    [SYS_ptrace] = {
        .number = SYS_ptrace,
        .name = "ptrace",
        .num_arguments = 4,
    },
    [SYS_getuid] = {
        .number = SYS_getuid,
        .name = "getuid",
        .num_arguments = 1,
    },
    [SYS_syslog] = {
        .number = SYS_syslog,
        .name = "syslog",
        .num_arguments = 3,
    },
    [SYS_getgid] = {
        .number = SYS_getgid,
        .name = "getgid",
        .num_arguments = 1,
    },
    [SYS_setuid] = {
        .number = SYS_setuid,
        .name = "setuid",
        .num_arguments = 1,
    },
    [SYS_setgid] = {
        .number = SYS_setgid,
        .name = "setgid",
        .num_arguments = 1,
    },
    [SYS_geteuid] = {
        .number = SYS_geteuid,
        .name = "geteuid",
        .num_arguments = 1,
    },
    [SYS_getegid] = {
        .number = SYS_getegid,
        .name = "getegid",
        .num_arguments = 1,
    },
    [SYS_setpgid] = {
        .number = SYS_setpgid,
        .name = "setpgid",
        .num_arguments = 2,
    },
    [SYS_getppid] = {
        .number = SYS_getppid,
        .name = "getppid",
        .num_arguments = 1,
    },
    [SYS_getpgrp] = {
        .number = SYS_getpgrp,
        .name = "getpgrp",
        .num_arguments = 0,
    },
    [SYS_setsid] = {
        .number = SYS_setsid,
        .name = "setsid",
        .num_arguments = 1,
    },
    [SYS_setreuid] = {
        .number = SYS_setreuid,
        .name = "setreuid",
        .num_arguments = 2,
    },
    [SYS_setregid] = {
        .number = SYS_setregid,
        .name = "setregid",
        .num_arguments = 2,
    },
    [SYS_getgroups] = {
        .number = SYS_getgroups,
        .name = "getgroups",
        .num_arguments = 2,
    },
    [SYS_setgroups] = {
        .number = SYS_setgroups,
        .name = "setgroups",
        .num_arguments = 2,
    },
    [SYS_setresuid] = {
        .number = SYS_setresuid,
        .name = "setresuid",
        .num_arguments = 3,
    },
    [SYS_getresuid] = {
        .number = SYS_getresuid,
        .name = "getresuid",
        .num_arguments = 3,
    },
    [SYS_setresgid] = {
        .number = SYS_setresgid,
        .name = "setresgid",
        .num_arguments = 3,
    },
    [SYS_getresgid] = {
        .number = SYS_getresgid,
        .name = "getresgid",
        .num_arguments = 3,
    },
    [SYS_getpgid] = {
        .number = SYS_getpgid,
        .name = "getpgid",
        .num_arguments = 1,
    },
    [SYS_setfsuid] = {
        .number = SYS_setfsuid,
        .name = "setfsuid",
        .num_arguments = 1,
    },
    [SYS_setfsgid] = {
        .number = SYS_setfsgid,
        .name = "setfsgid",
        .num_arguments = 1,
    },
    [SYS_getsid] = {
        .number = SYS_getsid,
        .name = "getsid",
        .num_arguments = 1,
    },
    [SYS_capget] = {
        .number = SYS_capget,
        .name = "capget",
        .num_arguments = 2,
    },
    [SYS_capset] = {
        .number = SYS_capset,
        .name = "capset",
        .num_arguments = 2,
    },
    [SYS_rt_sigpending] = {
        .number = SYS_rt_sigpending,
        .name = "rt_sigpending",
        .num_arguments = 6,
    },
    [SYS_rt_sigtimedwait] = {
        .number = SYS_rt_sigtimedwait,
        .name = "rt_sigtimedwait",
        .num_arguments = 6,
    },
    [SYS_rt_sigqueueinfo] = {
        .number = SYS_rt_sigqueueinfo,
        .name = "rt_sigqueueinfo",
        .num_arguments = 6,
    },
    [SYS_rt_sigsuspend] = {
        .number = SYS_rt_sigsuspend,
        .name = "rt_sigsuspend",
        .num_arguments = 6,
    },
    [SYS_sigaltstack] = {
        .number = SYS_sigaltstack,
        .name = "sigaltstack",
        .num_arguments = 2,
    },
    [SYS_utime] = {
        .number = SYS_utime,
        .name = "utime",
        .num_arguments = 2,
    },
    [SYS_mknod] = {
        .number = SYS_mknod,
        .name = "mknod",
        .num_arguments = 3,
    },
    [SYS_uselib] = {
        .number = SYS_uselib,
        .name = "uselib",
        .num_arguments = 1,
    },
    [SYS_personality] = {
        .number = SYS_personality,
        .name = "personality",
        .num_arguments = 1,
    },
    [SYS_ustat] = {
        .number = SYS_ustat,
        .name = "ustat",
        .num_arguments = 2,
    },
    [SYS_fstatfs] = {
        .number = SYS_fstatfs,
        .name = "fstatfs",
        .num_arguments = 2,
    },
    [SYS_sysfs] = {
        .number = SYS_sysfs,
        .name = "sysfs",
        .num_arguments = 2,
    },
    [SYS_getpriority] = {
        .number = SYS_getpriority,
        .name = "getpriority",
        .num_arguments = 2,
    },
    [SYS_setpriority] = {
        .number = SYS_setpriority,
        .name = "setpriority",
        .num_arguments = 3,
    },
    [SYS_sched_setparam] = {
        .number = SYS_sched_setparam,
        .name = "sched_setparam",
        .num_arguments = 2,
    },
    [SYS_sched_getparam] = {
        .number = SYS_sched_getparam,
        .name = "sched_getparam",
        .num_arguments = 2,
    },
    [SYS_sched_setscheduler] = {
        .number = SYS_sched_setscheduler,
        .name = "sched_setscheduler",
        .num_arguments = 3,
    },
    [SYS_sched_getscheduler] = {
        .number = SYS_sched_getscheduler,
        .name = "sched_getscheduler",
        .num_arguments = 1,
    },
    [SYS_sched_get_priority_max] = {
        .number = SYS_sched_get_priority_max,
        .name = "sched_get_priority_max",
        .num_arguments = 1,
    },
    [SYS_sched_get_priority_min] = {
        .number = SYS_sched_get_priority_min,
        .name = "sched_get_priority_min",
        .num_arguments = 1,
    },
    [SYS_sched_rr_get_interval] = {
        .number = SYS_sched_rr_get_interval,
        .name = "sched_rr_get_interval",
        .num_arguments = 2,
    },
    [SYS_mlock] = {
        .number = SYS_mlock,
        .name = "mlock",
        .num_arguments = 2,
    },
    [SYS_munlock] = {
        .number = SYS_munlock,
        .name = "munlock",
        .num_arguments = 2,
    },
    [SYS_mlockall] = {
        .number = SYS_mlockall,
        .name = "mlockall",
        .num_arguments = 1,
    },
    [SYS_munlockall] = {
        .number = SYS_munlockall,
        .name = "munlockall",
        .num_arguments = 1,
    },
    [SYS_vhangup] = {
        .number = SYS_vhangup,
        .name = "vhangup",
        .num_arguments = 1,
    },
    [SYS_modify_ldt] = {
        .number = SYS_modify_ldt,
        .name = "modify_ldt",
        .num_arguments = 3,
    },
    [SYS_pivot_root] = {
        .number = SYS_pivot_root,
        .name = "pivot_root",
        .num_arguments = 2,
    },
    [SYS__sysctl] = {
        .number = SYS__sysctl,
        .name = "_sysctl",
        .num_arguments = 1,
    },
    [SYS_prctl] = {
        .number = SYS_prctl,
        .name = "prctl",
        .num_arguments = 5,
    },
    [SYS_adjtimex] = {
        .number = SYS_adjtimex,
        .name = "adjtimex",
        .num_arguments = 1,
    },
    [SYS_setrlimit] = {
        .number = SYS_setrlimit,
        .name = "setrlimit",
        .num_arguments = 2,
    },
    [SYS_chroot] = {
        .number = SYS_chroot,
        .name = "chroot",
        .num_arguments = 1,
    },
    [SYS_sync] = {
        .number = SYS_sync,
        .name = "sync",
        .num_arguments = 1,
    },
    [SYS_acct] = {
        .number = SYS_acct,
        .name = "acct",
        .num_arguments = 1,
    },
    [SYS_settimeofday] = {
        .number = SYS_settimeofday,
        .name = "settimeofday",
        .num_arguments = 2,
    },
    [SYS_mount] = {
        .number = SYS_mount,
        .name = "mount",
        .num_arguments = 5,
    },
    [SYS_umount2] = {
        .number = SYS_umount2,
        .name = "umount2",
        .num_arguments = 2,
    },
    [SYS_swapon] = {
        .number = SYS_swapon,
        .name = "swapon",
        .num_arguments = 2,
    },
    [SYS_swapoff] = {
        .number = SYS_swapoff,
        .name = "swapoff",
        .num_arguments = 1,
    },
    [SYS_reboot] = {
        .number = SYS_reboot,
        .name = "reboot",
        .num_arguments = 4,
    },
    [SYS_sethostname] = {
        .number = SYS_sethostname,
        .name = "sethostname",
        .num_arguments = 2,
    },
    [SYS_setdomainname] = {
        .number = SYS_setdomainname,
        .name = "setdomainname",
        .num_arguments = 2,
    },
    [SYS_iopl] = {
        .number = SYS_iopl,
        .name = "iopl",
        .num_arguments = 1,
    },
    [SYS_ioperm] = {
        .number = SYS_ioperm,
        .name = "ioperm",
        .num_arguments = 3,
    },
    [SYS_create_module] = {
        .number = SYS_create_module,
        .name = "create_module",
        .num_arguments = 2,
    },
    [SYS_init_module] = {
        .number = SYS_init_module,
        .name = "init_module",
        .num_arguments = 3,
    },
    [SYS_delete_module] = {
        .number = SYS_delete_module,
        .name = "delete_module",
        .num_arguments = 2,
    },
    [SYS_get_kernel_syms] = {
        .number = SYS_get_kernel_syms,
        .name = "get_kernel_syms",
        .num_arguments = 1,
    },
    [SYS_query_module] = {
        .number = SYS_query_module,
        .name = "query_module",
        .num_arguments = 5,
    },
    [SYS_quotactl] = {
        .number = SYS_quotactl,
        .name = "quotactl",
        .num_arguments = 4,
    },
    [SYS_nfsservctl] = {
        .number = SYS_nfsservctl,
        .name = "nfsservctl",
        .num_arguments = 3,
    },
    [SYS_getpmsg] = {
        .number = SYS_getpmsg,
        .name = "getpmsg",
        .num_arguments = 6,
    },
    [SYS_putpmsg] = {
        .number = SYS_putpmsg,
        .name = "putpmsg",
        .num_arguments = 6,
    },
    [SYS_afs_syscall] = {
        .number = SYS_afs_syscall,
        .name = "afs_syscall",
        .num_arguments = 6,
    },
    [SYS_tuxcall] = {
        .number = SYS_tuxcall,
        .name = "tuxcall",
        .num_arguments = 6,
    },
    [SYS_security] = {
        .number = SYS_security,
        .name = "security",
        .num_arguments = 6,
    },
    [SYS_gettid] = {
        .number = SYS_gettid,
        .name = "gettid",
        .num_arguments = 1,
    },
    [SYS_readahead] = {
        .number = SYS_readahead,
        .name = "readahead",
        .num_arguments = 3,
    },
    [SYS_setxattr] = {
        .number = SYS_setxattr,
        .name = "setxattr",
        .num_arguments = 5,
    },
    [SYS_lsetxattr] = {
        .number = SYS_lsetxattr,
        .name = "lsetxattr",
        .num_arguments = 5,
    },
    [SYS_fsetxattr] = {
        .number = SYS_fsetxattr,
        .name = "fsetxattr",
        .num_arguments = 5,
    },
    [SYS_getxattr] = {
        .number = SYS_getxattr,
        .name = "getxattr",
        .num_arguments = 4,
    },
    [SYS_lgetxattr] = {
        .number = SYS_lgetxattr,
        .name = "lgetxattr",
        .num_arguments = 4,
    },
    [SYS_fgetxattr] = {
        .number = SYS_fgetxattr,
        .name = "fgetxattr",
        .num_arguments = 4,
    },
    [SYS_listxattr] = {
        .number = SYS_listxattr,
        .name = "listxattr",
        .num_arguments = 3,
    },
    [SYS_llistxattr] = {
        .number = SYS_llistxattr,
        .name = "llistxattr",
        .num_arguments = 3,
    },
    [SYS_flistxattr] = {
        .number = SYS_flistxattr,
        .name = "flistxattr",
        .num_arguments = 3,
    },
    [SYS_removexattr] = {
        .number = SYS_removexattr,
        .name = "removexattr",
        .num_arguments = 2,
    },
    [SYS_lremovexattr] = {
        .number = SYS_lremovexattr,
        .name = "lremovexattr",
        .num_arguments = 2,
    },
    [SYS_fremovexattr] = {
        .number = SYS_fremovexattr,
        .name = "fremovexattr",
        .num_arguments = 2,
    },
    [SYS_tkill] = {
        .number = SYS_tkill,
        .name = "tkill",
        .num_arguments = 2,
    },
    [SYS_time] = {
        .number = SYS_time,
        .name = "time",
        .num_arguments = 1,
    },
    [SYS_sched_setaffinity] = {
        .number = SYS_sched_setaffinity,
        .name = "sched_setaffinity",
        .num_arguments = 3,
    },
    [SYS_sched_getaffinity] = {
        .number = SYS_sched_getaffinity,
        .name = "sched_getaffinity",
        .num_arguments = 3,
    },
    [SYS_set_thread_area] = {
        .number = SYS_set_thread_area,
        .name = "set_thread_area",
        .num_arguments = 1,
    },
    [SYS_io_setup] = {
        .number = SYS_io_setup,
        .name = "io_setup",
        .num_arguments = 2,
    },
    [SYS_io_destroy] = {
        .number = SYS_io_destroy,
        .name = "io_destroy",
        .num_arguments = 1,
    },
    [SYS_io_getevents] = {
        .number = SYS_io_getevents,
        .name = "io_getevents",
        .num_arguments = 5,
    },
    [SYS_io_submit] = {
        .number = SYS_io_submit,
        .name = "io_submit",
        .num_arguments = 3,
    },
    [SYS_io_cancel] = {
        .number = SYS_io_cancel,
        .name = "io_cancel",
        .num_arguments = 3,
    },
    [SYS_get_thread_area] = {
        .number = SYS_get_thread_area,
        .name = "get_thread_area",
        .num_arguments = 1,
    },
    [SYS_lookup_dcookie] = {
        .number = SYS_lookup_dcookie,
        .name = "lookup_dcookie",
        .num_arguments = 3,
    },
    [SYS_epoll_create] = {
        .number = SYS_epoll_create,
        .name = "epoll_create",
        .num_arguments = 1,
    },
    [SYS_epoll_ctl_old] = {
        .number = SYS_epoll_ctl_old,
        .name = "epoll_ctl_old",
        .num_arguments = 6,
    },
    [SYS_epoll_wait_old] = {
        .number = SYS_epoll_wait_old,
        .name = "epoll_wait_old",
        .num_arguments = 6,
    },
    [SYS_remap_file_pages] = {
        .number = SYS_remap_file_pages,
        .name = "remap_file_pages",
        .num_arguments = 5,
        .flags = STRACE_SYSCALL_ENTRY_MEMORY_MAPPING_CHANGE,
    },
    [SYS_getdents64] = {
        .number = SYS_getdents64,
        .name = "getdents64",
        .num_arguments = 3,
    },
    [SYS_restart_syscall] = {
        .number = SYS_restart_syscall,
        .name = "restart_syscall",
        .num_arguments = 1,
    },
    [SYS_semtimedop] = {
        .number = SYS_semtimedop,
        .name = "semtimedop",
        .num_arguments = 4,
    },
    [SYS_fadvise64] = {
        .number = SYS_fadvise64,
        .name = "fadvise64",
        .num_arguments = 6,
    },
    [SYS_timer_create] = {
        .number = SYS_timer_create,
        .name = "timer_create",
        .num_arguments = 3,
    },
    [SYS_timer_settime] = {
        .number = SYS_timer_settime,
        .name = "timer_settime",
        .num_arguments = 4,
    },
    [SYS_timer_gettime] = {
        .number = SYS_timer_gettime,
        .name = "timer_gettime",
        .num_arguments = 2,
    },
    [SYS_timer_getoverrun] = {
        .number = SYS_timer_getoverrun,
        .name = "timer_getoverrun",
        .num_arguments = 1,
    },
    [SYS_timer_delete] = {
        .number = SYS_timer_delete,
        .name = "timer_delete",
        .num_arguments = 1,
    },
    [SYS_clock_settime] = {
        .number = SYS_clock_settime,
        .name = "clock_settime",
        .num_arguments = 2,
    },
    [SYS_clock_gettime] = {
        .number = SYS_clock_gettime,
        .name = "clock_gettime",
        .num_arguments = 2,
    },
    [SYS_clock_getres] = {
        .number = SYS_clock_getres,
        .name = "clock_getres",
        .num_arguments = 2,
    },
    [SYS_clock_nanosleep] = {
        .number = SYS_clock_nanosleep,
        .name = "clock_nanosleep",
        .num_arguments = 4,
    },
    [SYS_epoll_wait] = {
        .number = SYS_epoll_wait,
        .name = "epoll_wait",
        .num_arguments = 4,
    },
    [SYS_epoll_ctl] = {
        .number = SYS_epoll_ctl,
        .name = "epoll_ctl",
        .num_arguments = 4,
    },
    [SYS_tgkill] = {
        .number = SYS_tgkill,
        .name = "tgkill",
        .num_arguments = 3,
    },
    [SYS_utimes] = {
        .number = SYS_utimes,
        .name = "utimes",
        .num_arguments = 2,
    },
    [SYS_vserver] = {
        .number = SYS_vserver,
        .name = "vserver",
        .num_arguments = 6,
    },
    [SYS_mbind] = {
        .number = SYS_mbind,
        .name = "mbind",
        .num_arguments = 6,
    },
    [SYS_set_mempolicy] = {
        .number = SYS_set_mempolicy,
        .name = "set_mempolicy",
        .num_arguments = 3,
    },
    [SYS_get_mempolicy] = {
        .number = SYS_get_mempolicy,
        .name = "get_mempolicy",
        .num_arguments = 5,
    },
    [SYS_mq_open] = {
        .number = SYS_mq_open,
        .name = "mq_open",
        .num_arguments = 2,
    },
    [SYS_mq_unlink] = {
        .number = SYS_mq_unlink,
        .name = "mq_unlink",
        .num_arguments = 1,
    },
    [SYS_mq_timedsend] = {
        .number = SYS_mq_timedsend,
        .name = "mq_timedsend",
        .num_arguments = 5,
    },
    [SYS_mq_timedreceive] = {
        .number = SYS_mq_timedreceive,
        .name = "mq_timedreceive",
        .num_arguments = 5,
    },
    [SYS_mq_notify] = {
        .number = SYS_mq_notify,
        .name = "mq_notify",
        .num_arguments = 2,
    },
    [SYS_mq_getsetattr] = {
        .number = SYS_mq_getsetattr,
        .name = "mq_getsetattr",
        .num_arguments = 3,
    },
    [SYS_kexec_load] = {
        .number = SYS_kexec_load,
        .name = "kexec_load",
        .num_arguments = 4,
    },
    [SYS_waitid] = {
        .number = SYS_waitid,
        .name = "waitid",
        .num_arguments = 4,
    },
    [SYS_add_key] = {
        .number = SYS_add_key,
        .name = "add_key",
        .num_arguments = 5,
    },
    [SYS_request_key] = {
        .number = SYS_request_key,
        .name = "request_key",
        .num_arguments = 4,
    },
    [SYS_keyctl] = {
        .number = SYS_keyctl,
        .name = "keyctl",
        .num_arguments = 2,
    },
    [SYS_ioprio_set] = {
        .number = SYS_ioprio_set,
        .name = "ioprio_set",
        .num_arguments = 3,
    },
    [SYS_ioprio_get] = {
        .number = SYS_ioprio_get,
        .name = "ioprio_get",
        .num_arguments = 2,
    },
    [SYS_inotify_init] = {
        .number = SYS_inotify_init,
        .name = "inotify_init",
        .num_arguments = 1,
    },
    [SYS_inotify_add_watch] = {
        .number = SYS_inotify_add_watch,
        .name = "inotify_add_watch",
        .num_arguments = 3,
    },
    [SYS_inotify_rm_watch] = {
        .number = SYS_inotify_rm_watch,
        .name = "inotify_rm_watch",
        .num_arguments = 2,
    },
    [SYS_migrate_pages] = {
        .number = SYS_migrate_pages,
        .name = "migrate_pages",
        .num_arguments = 4,
    },
    [SYS_mkdirat] = {
        .number = SYS_mkdirat,
        .name = "mkdirat",
        .num_arguments = 3,
    },
    [SYS_mknodat] = {
        .number = SYS_mknodat,
        .name = "mknodat",
        .num_arguments = 4,
    },
    [SYS_fchownat] = {
        .number = SYS_fchownat,
        .name = "fchownat",
        .num_arguments = 5,
    },
    [SYS_futimesat] = {
        .number = SYS_futimesat,
        .name = "futimesat",
        .num_arguments = 3,
    },
    [SYS_unlinkat] = {
        .number = SYS_unlinkat,
        .name = "unlinkat",
        .num_arguments = 3,
    },
    [SYS_renameat] = {
        .number = SYS_renameat,
        .name = "renameat",
        .num_arguments = 4,
    },
    [SYS_linkat] = {
        .number = SYS_linkat,
        .name = "linkat",
        .num_arguments = 5,
    },
    [SYS_symlinkat] = {
        .number = SYS_symlinkat,
        .name = "symlinkat",
        .num_arguments = 3,
    },
    [SYS_readlinkat] = {
        .number = SYS_readlinkat,
        .name = "readlinkat",
        .num_arguments = 4,
    },
    [SYS_fchmodat] = {
        .number = SYS_fchmodat,
        .name = "fchmodat",
        .num_arguments = 4,
    },
    [SYS_faccessat] = {
        .number = SYS_faccessat,
        .name = "faccessat",
        .num_arguments = 4,
    },
    [SYS_pselect6] = {
        .number = SYS_pselect6,
        .name = "pselect6",
        .num_arguments = 6,
    },
    [SYS_ppoll] = {
        .number = SYS_ppoll,
        .name = "ppoll",
        .num_arguments = 4,
    },
    [SYS_unshare] = {
        .number = SYS_unshare,
        .name = "unshare",
        .num_arguments = 1,
    },
    [SYS_get_robust_list] = {
        .number = SYS_get_robust_list,
        .name = "get_robust_list",
        .num_arguments = 3,
    },
    [SYS_splice] = {
        .number = SYS_splice,
        .name = "splice",
        .num_arguments = 6,
    },
    [SYS_tee] = {
        .number = SYS_tee,
        .name = "tee",
        .num_arguments = 4,
    },
    [SYS_sync_file_range] = {
        .number = SYS_sync_file_range,
        .name = "sync_file_range",
        .num_arguments = 4,
    },
    [SYS_vmsplice] = {
        .number = SYS_vmsplice,
        .name = "vmsplice",
        .num_arguments = 4,
    },
    [SYS_move_pages] = {
        .number = SYS_move_pages,
        .name = "move_pages",
        .num_arguments = 6,
    },
    [SYS_utimensat] = {
        .number = SYS_utimensat,
        .name = "utimensat",
        .num_arguments = 4,
    },
    [SYS_epoll_pwait] = {
        .number = SYS_epoll_pwait,
        .name = "epoll_pwait",
        .num_arguments = 5,
    },
    [SYS_signalfd] = {
        .number = SYS_signalfd,
        .name = "signalfd",
        .num_arguments = 3,
    },
    [SYS_timerfd_create] = {
        .number = SYS_timerfd_create,
        .name = "timerfd_create",
        .num_arguments = 2,
    },
    [SYS_eventfd] = {
        .number = SYS_eventfd,
        .name = "eventfd",
        .num_arguments = 2,
    },
    [SYS_fallocate] = {
        .number = SYS_fallocate,
        .name = "fallocate",
        .num_arguments = 4,
    },
    [SYS_timerfd_settime] = {
        .number = SYS_timerfd_settime,
        .name = "timerfd_settime",
        .num_arguments = 4,
    },
    [SYS_timerfd_gettime] = {
        .number = SYS_timerfd_gettime,
        .name = "timerfd_gettime",
        .num_arguments = 2,
    },
    [SYS_accept4] = {
        .number = SYS_accept4,
        .name = "accept4",
        .num_arguments = 4,
    },
    [SYS_signalfd4] = {
        .number = SYS_signalfd4,
        .name = "signalfd4",
        .num_arguments = 6,
    },
    [SYS_eventfd2] = {
        .number = SYS_eventfd2,
        .name = "eventfd2",
        .num_arguments = 6,
    },
    [SYS_epoll_create1] = {
        .number = SYS_epoll_create1,
        .name = "epoll_create1",
        .num_arguments = 1,
    },
    [SYS_dup3] = {
        .number = SYS_dup3,
        .name = "dup3",
        .num_arguments = 3,
    },
    [SYS_pipe2] = {
        .number = SYS_pipe2,
        .name = "pipe2",
        .num_arguments = 2,
    },
    [SYS_inotify_init1] = {
        .number = SYS_inotify_init1,
        .name = "inotify_init1",
        .num_arguments = 1,
    },
    [SYS_preadv] = {
        .number = SYS_preadv,
        .name = "preadv",
        .num_arguments = 4,
    },
    [SYS_pwritev] = {
        .number = SYS_pwritev,
        .name = "pwritev",
        .num_arguments = 4,
    },
    [SYS_rt_tgsigqueueinfo] = {
        .number = SYS_rt_tgsigqueueinfo,
        .name = "rt_tgsigqueueinfo",
        .num_arguments = 6,
    },
    [SYS_perf_event_open] = {
        .number = SYS_perf_event_open,
        .name = "perf_event_open",
        .num_arguments = 5,
    },
    [SYS_recvmmsg] = {
        .number = SYS_recvmmsg,
        .name = "recvmmsg",
        .num_arguments = 5,
    },
    [SYS_fanotify_init] = {
        .number = SYS_fanotify_init,
        .name = "fanotify_init",
        .num_arguments = 2,
    },
    [SYS_fanotify_mark] = {
        .number = SYS_fanotify_mark,
        .name = "fanotify_mark",
        .num_arguments = 5,
    },
    [SYS_name_to_handle_at] = {
        .number = SYS_name_to_handle_at,
        .name = "name_to_handle_at",
        .num_arguments = 5,
    },
    [SYS_open_by_handle_at] = {
        .number = SYS_open_by_handle_at,
        .name = "open_by_handle_at",
        .num_arguments = 3,
    },
    [SYS_clock_adjtime] = {
        .number = SYS_clock_adjtime,
        .name = "clock_adjtime",
        .num_arguments = 6,
    },
    [SYS_syncfs] = {
        .number = SYS_syncfs,
        .name = "syncfs",
        .num_arguments = 1,
    },
    [SYS_sendmmsg] = {
        .number = SYS_sendmmsg,
        .name = "sendmmsg",
        .num_arguments = 4,
    },
    [SYS_setns] = {
        .number = SYS_setns,
        .name = "setns",
        .num_arguments = 2,
    },
    [SYS_getcpu] = {
        .number = SYS_getcpu,
        .name = "getcpu",
        .num_arguments = 3,
    },
    [SYS_process_vm_readv] = {
        .number = SYS_process_vm_readv,
        .name = "process_vm_readv",
        .num_arguments = 6,
    },
    [SYS_process_vm_writev] = {
        .number = SYS_process_vm_writev,
        .name = "process_vm_writev",
        .num_arguments = 6,
    },
    [SYS_kcmp] = {
        .number = SYS_kcmp,
        .name = "kcmp",
        .num_arguments = 5,
    },
    [SYS_finit_module] = {
        .number = SYS_finit_module,
        .name = "finit_module",
        .num_arguments = 3,
    },
    [SYS_sched_setattr] = {
        .number = SYS_sched_setattr,
        .name = "sched_setattr",
        .num_arguments = 3,
    },
    [SYS_sched_getattr] = {
        .number = SYS_sched_getattr,
        .name = "sched_getattr",
        .num_arguments = 4,
    },
    [SYS_renameat2] = {
        .number = SYS_renameat2,
        .name = "renameat2",
        .num_arguments = 5,
    },
    [SYS_seccomp] = {
        .number = SYS_seccomp,
        .name = "seccomp",
        .num_arguments = 3,
    },
    [SYS_memfd_create] = {
        .number = SYS_memfd_create,
        .name = "memfd_create",
        .num_arguments = 2,
    },
    [SYS_kexec_file_load] = {
        .number = SYS_kexec_file_load,
        .name = "kexec_file_load",
        .num_arguments = 5,
    },
    [SYS_bpf] = {
        .number = SYS_bpf,
        .name = "bpf",
        .num_arguments = 3,
    },
    [SYS_userfaultfd] = {
        .number = SYS_userfaultfd,
        .name = "userfaultfd",
        .num_arguments = 6,
    },
    [SYS_membarrier] = {
        .number = SYS_membarrier,
        .name = "membarrier",
        .num_arguments = 2,
    },
    [SYS_mlock2] = {
        .number = SYS_mlock2,
        .name = "mlock2",
        .num_arguments = 3,
    },
    [SYS_copy_file_range] = {
        .number = SYS_copy_file_range,
        .name = "copy_file_range",
        .num_arguments = 6,
    },
    [SYS_preadv2] = {
        .number = SYS_preadv2,
        .name = "preadv2",
        .num_arguments = 5,
    },
    [SYS_pwritev2] = {
        .number = SYS_pwritev2,
        .name = "pwritev2",
        .num_arguments = 5,
    },
    [SYS_pkey_free] = {
        .number = SYS_pkey_free,
        .name = "pkey_free",
        .num_arguments = 1,
    },
};
static const size_t STRACE_SYSCALL_ENTRIES_COUNT =
    (sizeof(STRACE_SYSCALL_ENTRIES) / sizeof(STRACE_SYSCALL_ENTRIES[0]));
