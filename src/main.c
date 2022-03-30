/*
** EPITECH PROJECT, 2022
** STRACE
** File description:
** main
*/

#include"strace.h"

int print_error(char *what)
{
    write(2, what, strlen(what));
    return (ERROR);
}

void usage()
{
    write(1, "USAGE: ./strace [-s] [-p <pid>|<command>]\n", 42);
}

int main(int ac, char **av)
{
    if (ac < 2)
        print_error("Not enought arguments");
    if (ac == 2 && strcmp("--help", av[1]) == 0) {
        usage();
    }
    return (0);
}