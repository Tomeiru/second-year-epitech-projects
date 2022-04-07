/*
** EPITECH PROJECT, 2022
** STRACE
** File description:
** main
*/

#include "strace.h"

int print_error(char *what)
{
    write(2, what, strlen(what));
    return (ERROR);
}

static char check_flags(int ac, char **av)
{
    char ret = 0;

    if (!strcmp(*av, "-s")) {
        if (ac-- == 1)
            return (-1);
        ret += 1;
        av++;
    }if (!strcmp(*av, "-p")) {
        if (ac != 2)
            return (-1);
        ret += 10;
    }
    return (ret);
}

static int strace_main(int ac, char **av, char **env)
{
    char flags = check_flags(ac, av);

    switch (flags) {
        case (-1):
            return (print_error("Wrong arguments\n"));
        case (11):
            return (strace_pid(av[2], 1));
        case (10):
            return (strace_pid(av[1], 0));
        case (1):
            return (strace_command(++av, 1, env));
        default:
            return (strace_command(av, 0, env));
    }
}

static int usage(void)
{
    write(1, "USAGE: ./strace [-s] [-p <pid>|<command>]\n", 42);
    return (0);
}

int main(int ac, char **av, char **env)
{
    UNUSED(table);
    if (ac < 2)
        return (print_error("Not enough argument\n"));
    if (ac == 2 && strcmp("--help", av[1]) == 0)
        return (usage());
    return (strace_main(--ac, ++av, env));
}