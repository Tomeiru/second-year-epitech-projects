/*
** EPITECH PROJECT, 2022
** myteamsss
** File description:
** list_transaction
*/

#include "cli_teams.h"
#include "logging_client.h"

void handle_list_team_transaction(client_t *client, void *data)
{
    size_t nb;
    uuid_t uuid;
    char name[MAX_NAME_LENGTH];
    char desc[MAX_DESCRIPTION_LENGTH];
    char uuid_str[36];

    UNUSED(data);
    puts("[INFO] List teams handle");
    read(client->conn->socket, &nb, sizeof(size_t));
    printf("%lu\n", nb);
    for (size_t i = 0; i < nb; i++) {
        read(client->conn->socket, uuid, sizeof(uuid_t));
        read(client->conn->socket, name, MAX_NAME_LENGTH);
        read(client->conn->socket, desc, MAX_DESCRIPTION_LENGTH);
        uuid_unparse(uuid, uuid_str);
        client_print_teams(uuid_str, name, desc);
    }
}

void handle_list_channel_transaction(client_t *client, void *data)
{
    uint nb;
    uuid_t uuid;
    char name[MAX_NAME_LENGTH];
    char desc[MAX_DESCRIPTION_LENGTH];
    char uuid_str[36];

    UNUSED(data);
    puts("[INFO] List channels handle");
    read(client->conn->socket, &nb, sizeof(uint));
    for (size_t i = 0; i < nb; i++) {
        read(client->conn->socket, uuid, sizeof(uuid_t));
        read(client->conn->socket, name, MAX_NAME_LENGTH);
        read(client->conn->socket, desc, MAX_DESCRIPTION_LENGTH);
        uuid_unparse(uuid, uuid_str);
        client_team_print_channels(uuid_str, name, desc);
    }
}

void handle_list_thread_transaction(client_t *client, void *data)
{
    uint nb;
    uuid_t thread_uuid;
    uuid_t user_uuid;
    char uuids[37 * 2] = {0};
    time_t timestamp;
    char name[MAX_NAME_LENGTH];
    char msg[MAX_BODY_LENGTH];

    UNUSED(data);
    read(client->conn->socket, &nb, sizeof(uint));
    for (size_t i = 0; i < nb; i++) {
        read(client->conn->socket, thread_uuid, sizeof(uuid_t));
        read(client->conn->socket, user_uuid, sizeof(uuid_t));
        read(client->conn->socket, &timestamp, sizeof(time_t));
        read(client->conn->socket, name, MAX_NAME_LENGTH);
        read(client->conn->socket, msg, MAX_BODY_LENGTH);
        uuid_unparse(thread_uuid, uuids);
        uuid_unparse(user_uuid, uuids + 37);
        client_channel_print_threads(uuids, uuids + 37, timestamp, name, msg);
    }
}

void handle_list_comment_transaction(client_t *client, void *data)
{
    uint nb;
    uuid_t thread_uuid;
    uuid_t user_uuid;
    char thread_str[36];
    char user_str[36];
    time_t timestamp;
    char msg[MAX_BODY_LENGTH];

    UNUSED(data);
    puts("[INFO] List comments handle");
    read(client->conn->socket, &nb, sizeof(uint));
    for (size_t i = 0; i < nb; i++) {
        read(client->conn->socket, thread_uuid, sizeof(uuid_t));
        read(client->conn->socket, user_uuid, sizeof(uuid_t));
        read(client->conn->socket, &timestamp, sizeof(time_t));
        read(client->conn->socket, msg, MAX_BODY_LENGTH);
        uuid_unparse(thread_uuid, thread_str);
        uuid_unparse(user_uuid, user_str);
        client_thread_print_replies(thread_str, user_str, timestamp, msg);
    }
}
