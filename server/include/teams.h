/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** myftp
*/

#ifndef MYFTP_H_
    #define MYFTP_H_

    #include <stdio.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <sys/types.h>
    #include <sys/time.h>
    #include <errno.h>
    #include <netinet/in.h>
    #include <string.h>
    #include <unistd.h>
    #include "chained_list.h"

typedef void (*command_execute_fct_t)(client_t *client, void *data);

typedef struct  server_s {
    int fd;
    struct sockaddr_in socket;
} server_t;

typedef struct command_s {
    int id;
    int size_args;
    command_execute_fct_t fct;
} command_t;

typedef struct client_s {
    int fd;
    struct sockaddr_in socket;
    char *ip;
    int port;
    command_t *request;
} client_t;

    int my_teams(int ac, char **av);

#endif /* !MYFTP_H_ */