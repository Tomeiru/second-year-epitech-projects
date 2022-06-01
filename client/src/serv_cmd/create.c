/*
** EPITECH PROJECT, 2022
** myteamss
** File description:
** create
*/

#include "cli_teams.h"
#include "logging_client.h"

bool event_team_created_cmd(client_t *client, list_t *transactions)
{
    uuid_t team_uuid;
    char uuid_str[36];
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];

    UNUSED(transactions);
    read(client->conn->socket, team_uuid, sizeof(uuid_t));
    read(client->conn->socket, name, MAX_NAME_LENGTH);
    read(client->conn->socket, description, MAX_DESCRIPTION_LENGTH);
    uuid_unparse(team_uuid, uuid_str);
    client_event_team_created(uuid_str, name, description);
    return (false);
}

bool event_channel_created_cmd(client_t *client, list_t *transactions)
{
    uuid_t channel_uuid;
    char uuid_str[36];
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];

    UNUSED(transactions);
    read(client->conn->socket, channel_uuid, sizeof(uuid_t));
    read(client->conn->socket, name, MAX_NAME_LENGTH);
    read(client->conn->socket, description, MAX_DESCRIPTION_LENGTH);
    uuid_unparse(channel_uuid, uuid_str);
    client_event_channel_created(uuid_str, name, description);
    return (false);
}

bool event_thread_created_cmd(client_t *client, list_t *transactions)
{
    uuid_t thread_uuid;
    uuid_t user_uuid;
    char uuid_str[36];
    char user_str[36];
    time_t timestamp;
    char name[MAX_NAME_LENGTH];
    char msg[MAX_BODY_LENGTH];

    UNUSED(transactions);
    read(client->conn->socket, thread_uuid, sizeof(uuid_t));
    read(client->conn->socket, user_uuid, sizeof(uuid_t));
    read(client->conn->socket, &timestamp, sizeof(time_t));
    read(client->conn->socket, name, MAX_NAME_LENGTH);
    read(client->conn->socket, msg, MAX_BODY_LENGTH);
    uuid_unparse(thread_uuid, uuid_str);
    uuid_unparse(user_uuid, user_str);
    client_event_thread_created(uuid_str, user_str, timestamp, name, msg);
    return (false);
}