/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** pm_reply
*/

#include "cli_teams.h"
#include "logging_client.h"

bool event_pm_received_cmd(client_t *client, list_t *transactions)
{
    uuid_t uuid;
    char uuid_str[36];
    char msg[MAX_BODY_LENGTH];

    UNUSED(transactions);
    read(client->conn->socket, uuid, sizeof(uuid_t));
    read(client->conn->socket, msg, MAX_BODY_LENGTH);
    uuid_unparse(uuid, uuid_str);
    client_event_private_message_received(uuid_str, msg);
    return false;
}
