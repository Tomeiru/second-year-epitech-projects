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