/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** teams
*/

#pragma once

#include <uuid/uuid.h>
#include "conn.h"
#include "transaction.h"
#include "chained_list.h"
#include "cmd_ids.h"

#define UNUSED(var) ((void) var)

typedef enum use_state_e {
    NO_USE_STATE,
    TEAM_USE_STATE,
    CHANNEL_USE_STATE,
    THREAD_USE_STATE,
} use_state_t;

typedef struct use_s {
    use_state_t state;
    uuid_t team;
    uuid_t channel;
    uuid_t thread;
} use_t;

typedef struct client_s {
    conn_t *conn;
    use_t *use;
    bool connected;
    bool logout;
    uuid_t uuid;
} client_t;

bool handle_server_msg(client_t *client, list_t *transations);
bool handle_user_cmd(client_t *client, list_t *transactions);

void client_send_cmd_id(conn_t *conn, command_id_t cmd);
void client_send_data(conn_t *conn, void *data, size_t size);
void client_send_cmd(conn_t *conn, command_id_t cmd, void *data, size_t size);
