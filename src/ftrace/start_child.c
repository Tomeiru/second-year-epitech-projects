/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines start_child
*/

#include "start_child.h"
#include "start_child_part2.h"
#include "do_ptrace_seize.h"
#include "save_errno_kill.h"
#include "do_exec.h"
#include "print_error_message/errno_and_die.h"
#include "print_error_message/and_die.h"
#include "process/add.h"
#include "process/do_post_attach.h"
#include "standard_fds/redirect.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <stdint.h>

static void ssc_part4(ssc_state_t *s)
{
    if (ftrace_do_ptrace_seize(s->self, s->self->child_pid,
        &s->ptrace_command)) {
        ftrace_save_errno_kill(s->self->child_pid, SIGKILL);
        ftrace_print_error_message_errno_and_die(s->self,
            "attach: ptrace(%s, %jd)", s->ptrace_command,
            (intmax_t)s->self->child_pid);
    }
    kill(s->self->child_pid, SIGCONT);
    s->process = ftrace_process_add(s->self, s->self->child_pid);
    ftrace_process_do_post_attach(s->self, s->process,
        STRACE_PROCESS_NO_DETACH_FIRST_EXEC | STRACE_PROCESS_HIDE_LOG);
    ftrace_standard_fds_redirect(s->self);
}

static void ssc_part3_2(ssc_state_t *s)
{
    s->self->child_pid = s->pid;
    while (waitpid(s->self->child_pid, &s->wait_status, WSTOPPED) < 0) {
        if (errno == EINTR)
            continue;
        ftrace_print_error_message_errno_and_die(s->self, "waitpid");
    }
    if (!WIFSTOPPED(s->wait_status) || WSTOPSIG(s->wait_status) != SIGSTOP) {
        ftrace_save_errno_kill(s->self->child_pid, SIGKILL);
        ftrace_print_error_message_errno_and_die(
            s->self, "Unexpected wait status %#x", s->wait_status);
    }
    ssc_part4(s);
}

static void ssc_part3(ssc_state_t *s)
{
    s->self->traced_process_params.argv = s->argv;
    s->self->traced_process_params.exec_pathname = s->pathname;
    if (s->pid == 0)
        ftrace_do_exec(s->self);
    if (elf_version(EV_CURRENT) == EV_NONE)
        ftrace_print_error_message_and_die(s->self, "Elf library "
            "initialization failed: %s", elf_errmsg(-1));
    s->self->child_elf_handle = elf_begin(s->self->child_fd, ELF_C_READ, NULL);
    if (s->self->child_elf_handle == NULL)
        ftrace_print_error_message_and_die(s->self, "elf_begin failed: %s",
            elf_errmsg(-1));
    ssc_part3_2(s);
}

static void ssc_part2(ssc_state_t *s)
{
    if (s->filename_length > (sizeof(s->pathname) - 1)) {
        errno = ENAMETOOLONG;
        ftrace_print_error_message_errno_and_die(s->self, "exec");
    }
    if (strchr(s->filename, '/') != NULL)
        memcpy(s->pathname, s->filename, s->filename_length + 1);
    else {
        s->path = getenv("PATH");
        ssc_do_loop(s);
        if (s->path == NULL || *s->path == '\0')
            s->pathname[0] = '\0';
    }
    s->self->child_fd = open(s->pathname, O_RDONLY);
    if (s->self->child_fd < 0 || fstat(s->self->child_fd, &s->stat_buffer) != 0)
        ftrace_print_error_message_errno_and_die(
            s->self, "Can't stat '%s'", s->pathname);
    s->pid = fork();
    if (s->pid < 0)
        ftrace_print_error_message_errno_and_die(s->self, "fork");
    ssc_part3(s);
}

void ftrace_start_child(struct ftrace *self, char **argv)
{
    ssc_state_t state = {
        .self = self,
        .argv = argv,
        .filename = argv[0],
        .filename_length = strlen(argv[0]),
    };

    ssc_part2(&state);
}
