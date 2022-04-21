/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** check_and_get_args
*/

#include "myftp.h"

int check_and_get_port(char *port)
{
    for (int i = 0; port[i]; i++) {
        if (!isdigit(port[i]))
            return (-1);
    }
    return (atoi(port));
}

char *check_and_get_path(char *path)
{
    struct stat statbuffer;

    if (stat(path, &statbuffer) == -1 || S_ISREG(statbuffer.st_mode))
        return (NULL);
    path = realpath(path, NULL);
    return (path);
}