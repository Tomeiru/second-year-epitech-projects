/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines start_child
*/

#include "start_child.h"
#include "print_error_message/errno_and_die.h"
#include "save_errno_kill.h"
#include "do_exec.h"
#include "do_ptrace_seize.h"
#include "process/add.h"
#include "process/do_post_attach.h"
#include "standard_fds/redirect.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdint.h>
#include <limits.h>

void strace_start_child(struct strace *self, char **argv)
{
    char pathname[PATH_MAX];
    const char *filename = argv[0];
    size_t filename_length = strlen(filename);
    struct stat stat_buffer;

    if (filename_length > (sizeof(pathname) - 1)) {
        errno = ENAMETOOLONG;
        strace_print_error_message_errno_and_die(self, "exec");
    }
    if (strchr(filename, '/') != NULL)
        memcpy(pathname, filename, filename_length + 1);
    else {
        const char *path = getenv("PATH");
        size_t before_colon;
        size_t after_colon;
        size_t pathname_length;

        for (; path != NULL && *path != '\0'; path += after_colon) {

            const char *colon = strchr(path, ':');

            if (colon != NULL) {
                before_colon = colon - path;
                after_colon = before_colon + 1;
            } else {
                before_colon = strlen(path);
                after_colon = before_colon;
            }
            if (before_colon == 0) {
                if (getcwd(pathname, PATH_MAX) == NULL)
                    continue;
                pathname_length = strlen(pathname);
            } else if (before_colon > sizeof(pathname) - 1)
                continue;
            else {
                strncpy(pathname, path, before_colon);
                pathname_length = before_colon;
            }
            if (pathname_length != 0 && pathname[pathname_length - 1] != '/')
                pathname[pathname_length++] = '/';
            if (filename_length + pathname_length > sizeof(pathname) - 1)
                continue;
            strcpy(pathname + pathname_length, filename);

            if (stat(pathname, &stat_buffer) == 0 &&
                S_ISREG(stat_buffer.st_mode) &&
                (stat_buffer.st_mode & 0111))
                break;
        }
        if (path == NULL || *path == '\0')
            pathname[0] = '\0';
    }
    if (stat(pathname, &stat_buffer) != 0)
        strace_print_error_message_errno_and_die(self, "Can't stat '%s'", pathname);
    pid_t pid = fork();
    if (pid < 0)
        strace_print_error_message_errno_and_die(self, "fork");
    self->traced_process_params.argv = argv;
    self->traced_process_params.exec_pathname = pathname;
    if (pid == 0)
        strace_do_exec(self);
    self->child_pid = pid;

    int wait_status;
    while (waitpid(self->child_pid, &wait_status, WSTOPPED) < 0) {
        if (errno == EINTR)
            continue;
        strace_print_error_message_errno_and_die(self, "waitpid");
    }
    if (!WIFSTOPPED(wait_status) || WSTOPSIG(wait_status) != SIGSTOP) {
        strace_save_errno_kill(self->child_pid, SIGKILL);
        strace_print_error_message_errno_and_die(self,
            "Unexpected wait status %#x", wait_status);
    }
    const char *ptrace_command;
    if (strace_do_ptrace_seize(self, self->child_pid, &ptrace_command)) {
        strace_save_errno_kill(self->child_pid, SIGKILL);
        strace_print_error_message_errno_and_die(self,
            "attach: ptrace(%s, %jd)", ptrace_command,
            (intmax_t)self->child_pid);
    }
    kill(self->child_pid, SIGCONT);
    struct strace_process *process = strace_process_add(self, self->child_pid);
    strace_process_do_post_attach(self, process,
        STRACE_PROCESS_NO_DETACH_FIRST_EXEC | STRACE_PROCESS_HIDE_LOG);
    strace_standard_fds_redirect(self);
}
