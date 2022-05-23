/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** login
*/

#include "teams.h"
#include "logging_server.h"

void login_cmd(client_t *client, server_t *server, void *data)
{
    login_cmd_arg_t *arg = data;
    user_t *user = get_user_by_name(arg->name, server->save);

    if (!user)
        user = user_create(arg->name, server->save);
    client_send_success(client, arg->transaction);
    client->logged = true;
    memcpy(client->uuid, user->uuid, sizeof(uuid_t));
}

void logout_cmd(client_t *client, server_t *server, void *data)
{
    logout_cmd_arg_t *arg = data;

    (void) server;
    if (!check_client_logged(client, arg->transaction))
        return;
    client->quit = true;
    client_send_success(client, arg->transaction);
}
