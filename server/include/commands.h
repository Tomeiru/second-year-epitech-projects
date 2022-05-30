/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** commands
*/

#pragma once

#include <stdlib.h>
#include <uuid/uuid.h>
#include "cmd_ids.h"
#include "cmd_args.h"
#include "save.h"

#define COMMANDS_NB 8

typedef struct client_s client_t;
typedef struct server_s server_t;

typedef void (*command_execute_fct_t)(client_t *client,
server_t *server, void *data);

typedef struct command_s {
    command_id_t id;
    size_t size_args;
    command_execute_fct_t fct;
} command_t;

void login_cmd(client_t *client, server_t *server, void *data);
void logout_cmd(client_t *client, server_t *server, void *data);
void create_team_cmd(client_t *client, server_t *server, void *data);
void create_channel_cmd(client_t *client, server_t *server, void *data);
void create_thread_cmd(client_t *client, server_t *server, void *data);
void create_comment_cmd(client_t *client, server_t *server, void *data);
void send_pm_cmd(client_t *client, server_t *server, void *data);
void get_pm_cmd(client_t *client, server_t *server, void *data);

const command_t *get_command_from_id(command_id_t id);

extern const command_t COMMANDS[COMMANDS_NB];
