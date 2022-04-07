/*
** EPITECH PROJECT, 2022
** strace
** File description:
** strace_command
*/

#include "strace.h"

int strace_command(char **command, int detailed, char **env)
{
    int is_abs = check_abs(command[0]);

    UNUSED(table);
    if (is_abs) {
        if (!check_existence(command[0])) {
            fprintf(stderr,
            "strace: Can't stat '%s': No such file or directory\n", command[0]);
            return (84);
        }
        if (fork_and_execve(command, detailed, env) == -1) {
            fprintf(stderr, "strace: Can't execve '%s'\n", command[0]);
            return (84);
        }
        return (0);
    }
    return (path_command(command, detailed, env));
}