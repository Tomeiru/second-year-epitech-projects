/*
** EPITECH PROJECT, 2022
** strace
** File description:
** strace_pid
*/

#include "strace.h"

static int is_string_number(char *str)
{
    UNUSED(table);
    for (int i = 0; str[i]; i++)
        if (isdigit(str[i]) == 0)
            return (0);
    return (1);
}

static int check_and_get_pid(char *pid)
{
    int ret = 0;

    if (strlen(pid) > 7 || !is_string_number(pid))
        return (-1);
    ret = atoi(pid);
    return (ret > 4194304 ? -1 : ret);
}

int strace_pid(char *pid_str, int detailed)
{
    int pid = check_and_get_pid(pid_str);
    int ret = 0;

    if (pid == -1)
        return (print_error("Wrong PID argument\n"));
    ptrace(PTRACE_ATTACH, pid, NULL, NULL);
    ret = parent_process_command(pid, detailed);
    ptrace(PTRACE_DETACH, pid, NULL, NULL);
    return (ret);
}