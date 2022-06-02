/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** login
*/

#include "cli_teams.h"
#include "logging_client.h"

bool event_login_serv_cmd(client_t *client, list_t *transactions)
{
    uuid_t user_uuid;
    char uuid_str[36];
    char name[MAX_NAME_LENGTH];

    UNUSED(transactions);
    read(client->conn->socket, user_uuid, sizeof(uuid_t));
    read(client->conn->socket, name, MAX_NAME_LENGTH);
    uuid_unparse(user_uuid, uuid_str);
    client_event_logged_in(uuid_str, name);
    return (false);
}

bool event_logout_serv_cmd(client_t *client, list_t *transactions)
{
    uuid_t user_uuid;
    char uuid_str[36];
    char name[MAX_NAME_LENGTH];

    UNUSED(transactions);
    read(client->conn->socket, user_uuid, sizeof(uuid_t));
    read(client->conn->socket, name, MAX_NAME_LENGTH);
    uuid_unparse(user_uuid, uuid_str);
    client_event_logged_out(uuid_str, name);
    return (false);
}
