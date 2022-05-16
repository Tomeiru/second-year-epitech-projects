/*
** EPITECH PROJECT, 2022
** teams
** File description:
** main
*/

#include "teams.h"

int main(int ac, char **av)
{
    if (ac == 2 && strcmp("-help", av[1]) == 0) {
        printf("USAGE: ./myteams_server port\n\n");
        printf("       port is the port number on which the server socket");
        printf(" listens.\n");
        return (0);
    } else if (ac != 2 || is_not_number(av[1]))
        return (84);
    return (start_server(atoi(av[1])));
}
