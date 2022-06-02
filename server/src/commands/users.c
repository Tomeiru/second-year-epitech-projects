/*
** EPITECH PROJECT, 2022
** myteamsss
** File description:
** users
*/

#include "teams.h"
#include "logging_server.h"
#include "macros.h"
#include "events.h"

void users_cmd(client_t *client, server_t *server, void *data)
{
    list_users_cmd_arg_t *arg = data;
    size_t len = (size_t) node_len(server->save->users);
    user_t *user;

    if (!check_client_logged(client, arg->transaction))
        return;
    client_send_success(client, arg->transaction);
    client_send_value(client, len, sizeof(size_t));
    for (list_t list = server->save->users; list; list = list->next) {
        user = (user_t *)list->data;
        client_send_data(client, user->uuid, sizeof(uuid_t));
        client_send_data(client, user->name, MAX_NAME_LENGTH);
        if (get_connected_client(user->uuid, server))
            client_send_value(client, true, sizeof(bool));
        else
            client_send_value(client, false, sizeof(bool));
    }
}

void user_cmd(client_t *client, server_t *server, void *data)
{
    info_user_cmd_arg_t *arg = data;
    user_t *user;

    if (!check_client_logged(client, arg->transaction)
    || !(user = GET_USER(client, arg, server->save)))
        return;
    client_send_success(client, arg->transaction);
    client_send_data(client, user->uuid, sizeof(uuid_t));
    client_send_data(client, user->name, MAX_NAME_LENGTH);
    if (get_connected_client(user->uuid, server))
        client_send_value(client, true, sizeof(size_t));
    else
        client_send_value(client, false, sizeof(size_t));
}