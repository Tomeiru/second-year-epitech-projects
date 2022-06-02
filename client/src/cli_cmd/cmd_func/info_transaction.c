/*
** EPITECH PROJECT, 2022
** myteamsss
** File description:
** info_transaction
*/

#include "cli_teams.h"
#include "logging_client.h"

void handle_info_user_transaction(client_t *client, void *data)
{
    uuid_t uuid;
    char name[MAX_NAME_LENGTH];
    size_t connected;
    char uuid_str[36];

    UNUSED(data);
    puts("[INFO] Info user command transaction");
    read(client->conn->socket, uuid, sizeof(uuid_t));
    read(client->conn->socket, name, MAX_NAME_LENGTH);
    read(client->conn->socket, &connected, sizeof(size_t));
    uuid_unparse(uuid, uuid_str);
    client_print_user(uuid_str, name, connected);
}

void handle_info_team_transaction(client_t *client, void *data)
{
    uuid_t team_uuid;
    char uuid_str[36];
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];

    UNUSED(data);
    read(client->conn->socket, team_uuid, sizeof(uuid_t));
    read(client->conn->socket, name, MAX_NAME_LENGTH);
    read(client->conn->socket, description, MAX_DESCRIPTION_LENGTH);
    uuid_unparse(team_uuid, uuid_str);
    client_print_team(uuid_str, name, description);
}

void handle_info_channel_transaction(client_t *client, void *data)
{
    uuid_t channel_uuid;
    char uuid_str[36];
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];

    UNUSED(data);
    read(client->conn->socket, channel_uuid, sizeof(uuid_t));
    read(client->conn->socket, name, MAX_NAME_LENGTH);
    read(client->conn->socket, description, MAX_DESCRIPTION_LENGTH);
    uuid_unparse(channel_uuid, uuid_str);
    client_print_channel(uuid_str, name, description);
}

void handle_info_thread_transaction(client_t *client, void *data)
{
    uuid_t thread_uuid;
    uuid_t user_uuid;
    char uuid_str[36];
    char user_str[36];
    time_t timestamp;
    char name[MAX_NAME_LENGTH];
    char msg[MAX_BODY_LENGTH];

    UNUSED(data);
    read(client->conn->socket, thread_uuid, sizeof(uuid_t));
    read(client->conn->socket, user_uuid, sizeof(uuid_t));
    read(client->conn->socket, &timestamp, sizeof(time_t));
    read(client->conn->socket, name, MAX_NAME_LENGTH);
    read(client->conn->socket, msg, MAX_BODY_LENGTH);
    uuid_unparse(thread_uuid, uuid_str);
    uuid_unparse(user_uuid, user_str);
    client_print_thread(uuid_str, user_str, timestamp, name, msg);
}