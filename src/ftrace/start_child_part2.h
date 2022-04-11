/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Part 2 of start_child
*/

#pragma once

#include "../ftrace.h"
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>

typedef struct ssc_state {
    struct ftrace *self;
    char **argv;
    char pathname[PATH_MAX];
    const char *filename;
    size_t filename_length;
    struct stat stat_buffer;
    const char *path;
    size_t before_colon;
    size_t after_colon;
    size_t pathname_length;
    const char *colon;
    pid_t pid;
    int wait_status;
    const char *ptrace_command;
    struct ftrace_process *process;
} ssc_state_t;

static bool ssc_do_loop_part2(ssc_state_t *s)
{
    if (s->before_colon == 0) {
        if (getcwd(s->pathname, PATH_MAX) == NULL)
            return (true);
        s->pathname_length = strlen(s->pathname);
    } else if (s->before_colon > sizeof(s->pathname) - 1)
        return (true);
    else {
        strncpy(s->pathname, s->path, s->before_colon);
        s->pathname_length = s->before_colon;
    }
    if (s->pathname_length != 0 && s->pathname[s->pathname_length - 1] != '/')
        s->pathname[s->pathname_length++] = '/';
    if (s->filename_length + s->pathname_length > sizeof(s->pathname) - 1)
        return (true);
    strcpy(s->pathname + s->pathname_length, s->filename);
    return (!((stat(s->pathname, &s->stat_buffer) == 0 &&
        S_ISREG(s->stat_buffer.st_mode) && (s->stat_buffer.st_mode & 0111))));
}

static void ssc_do_loop(ssc_state_t *s)
{
    for (; s->path != NULL && *s->path != '\0'; s->path += s->after_colon) {
        s->colon = strchr(s->path, ':');
        if (s->colon != NULL) {
            s->before_colon = s->colon - s->path;
            s->after_colon = s->before_colon + 1;
        } else {
            s->before_colon = strlen(s->path);
            s->after_colon = s->before_colon;
        }
        if (!ssc_do_loop_part2(s))
            break;
    }
}
