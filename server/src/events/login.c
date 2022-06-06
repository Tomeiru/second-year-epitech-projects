/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** login
*/

#include "teams.h"
#include "cmd_ids.h"

void event_user_logged_in(server_t *server, user_t *user)
{
    client_t *client;
    char uuid_str[36];

    uuid_unparse(user->uuid, uuid_str);
    server_event_user_logged_in(uuid_str);
    for (list_t list = server->clients; list; list = list->next) {
        client = (client_t *)list->data;
        if (!client->logged)
            continue;
        client_send_value(client, EVENT_USER_LOGIN_ID, sizeof(command_id_t));
        client_send_data(client, user->uuid, sizeof(uuid_t));
        client_send_data(client, user->name, MAX_NAME_LENGTH);
    }
}

void event_user_logged_out(server_t *server, user_t *user)
{
    client_t *client;
    char uuid_str[36];

    uuid_unparse(user->uuid, uuid_str);
    server_event_user_logged_out(uuid_str);
    for (list_t list = server->clients; list; list = list->next) {
        client = (client_t *) list->data;
        if (!client->logged)
            continue;
        client->logged = false;
        client_send_value(client, EVENT_USER_LOGOUT_ID, sizeof(command_id_t));
        client_send_data(client, user->uuid, sizeof(uuid_t));
        client_send_data(client, user->name, MAX_NAME_LENGTH);
    }
}
