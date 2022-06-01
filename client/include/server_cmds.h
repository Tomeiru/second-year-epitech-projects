/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** server_cmds
*/

#pragma once

#include "chained_list.h"
#include "cmd_ids.h"
#include <stdbool.h>

#define SERV_CMD_NB 6

typedef struct client_s client_t;

typedef bool (*serv_cmd_execute_fct_t)(client_t *client, list_t *transations);

typedef struct serv_cmd_s {
    command_id_t id;
    serv_cmd_execute_fct_t fct;
} serv_cmd_t;

bool reponse_serv_cmd(client_t *client, list_t *transactions);
bool event_login_serv_cmd(client_t *client, list_t *transactions);
bool event_logout_serv_cmd(client_t *client, list_t *transactions);
bool event_team_created_cmd(client_t *client, list_t *transactions);
bool event_channel_created_cmd(client_t *client, list_t *transactions);
bool event_thread_created_cmd(client_t *client, list_t *transactions);

extern const serv_cmd_t SERV_CMDS[SERV_CMD_NB];
