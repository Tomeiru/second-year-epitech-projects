/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** myftp
*/

#pragma once

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
#include <stdbool.h>
#include "commands.h"
#include "chained_list.h"
#include "safe_malloc.h"

typedef unsigned int uint;
typedef struct sockaddr sockaddr_t;
typedef struct sockaddr_in sockaddr_in_t;
typedef struct timeval timeval_t;

typedef struct  server_s {
    int fd;
    struct sockaddr_in socket;
} server_t;

typedef struct client_s {
    int fd;
    sockaddr_in_t sockaddr;
    bool quit;
} client_t;

server_t *init_server(int port);
server_t *init_serv_struct(int port, int opt);
int start_server(int port);
void server_update(server_t *srv, list_t *list, fd_set *readfds, int max);

int set_fd(fd_set *readfds, server_t *server, list_t list);
bool accept_new_clients(int socket, list_t *list);

client_t *client_create(int fd, sockaddr_in_t *sockaddr, list_t *list);
void client_delete(client_t *client);
void client_update(client_t *client, server_t *srv);

int is_not_number(char *s);
