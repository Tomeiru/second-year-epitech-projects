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
#include "logging_server.h"
#include "save.h"
#include "typedefs.h"
#include "responses.h"
#include "utils.h"

#define SAVEFILE_PATH "./teams.dat"

typedef struct  server_s {
    int fd;
    sockaddr_in_t socket;
    save_t *save;
    list_t clients;
} server_t;

typedef struct client_s {
    int fd;
    sockaddr_in_t sockaddr;
    bool quit;
    bool logged;
    uuid_t uuid;
} client_t;

server_t *init_server(int port);
server_t *init_serv_struct(int port, int opt);
int start_server(int port);
void server_update(server_t *srv, fd_set *readfds, int max);

int set_fd(fd_set *readfds, server_t *server);
bool accept_new_clients(server_t *server);

client_t *client_create(int fd, sockaddr_in_t *sockaddr, list_t *list);
void client_delete(client_t *client);
void client_update(client_t *client, server_t *srv);

void client_send_array(client_t *client, void *data, size_t size, size_t n);
void client_send_linked_list(client_t *client, list_t list, size_t size);
void client_send_data(client_t *client, void *data, size_t size);
void client_send_value(client_t *client, size_t value, size_t size);

void client_send_success(client_t *client, uint64_t transaction);
void client_send_error(client_t *client,
uint64_t transaction, error_t error, uuid_t *uuid);
void client_send_unknown_cmd(client_t *client);

bool check_client_logged(client_t *client, uint64_t transation);
bool check_user_belongs_to_team(client_t *client, team_t *team, uint64_t transation, bool throw);
team_t *get_team_or_error(client_t *client,
uuid_t uuid, save_t *save, uint64_t transaction);
channel_t *get_channel_or_error(client_t *client,
uuid_t uuid, team_t *team, uint64_t transaction);
thread_t *get_thread_or_error(client_t *client,
uuid_t uuid, channel_t *channel, uint64_t transaction);
user_t *get_user_or_error(client_t *client,
uuid_t uuid, save_t *save, uint64_t transaction);

int is_not_number(char *s);
