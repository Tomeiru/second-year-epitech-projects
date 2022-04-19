/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** main
*/

#include "myftp.h"

static int print_help(void)
{
    printf("USAGE: ./myftp port path\n       port  is the port number on which \
the server socket listens\n       path  is the path to the home directory for t\
he Anonymous user\n");
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && !strcmp(av[1], "-help"))
        return (print_help());
    if (ac != 3)
        return (print_error("wrong number of argument provided (use -help)"));
    return (myftp(av + 1));
}