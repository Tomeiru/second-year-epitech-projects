/*
** EPITECH PROJECT, 2022
** teams
** File description:
** my_teams
*/

#include "teams.h"

int is_number(char *s)
{
    for (int i = 0; s[i]!= '\0'; i++) {
        if (isdigit(s[i]) == 0)
            return (0);
    }
    return (1);
}

int error_management(int ac, char **av)
{
    if (ac == 2 && is_number(av[1]))
        return (0);
    if (ac == 2 && strcmp("-help", av[1]) == 0) {
        printf("USAGE: ./myteams_server port\n\n");
        printf("       port is the port number on which the server socket");
        printf(" listens.\n");
        exit(0);
    }
    return (1);
}

int my_teams(int ac, char **av)
{
    if (error_management(ac, av))
        return (84);
    printf("OK\n");
    return (0);
}