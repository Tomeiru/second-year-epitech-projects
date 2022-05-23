/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** login
*/

#include "teams.h"
#include "logging_server.h"

void login_cmd(client_t *client, save_t *save, void *data)
{
    login_cmd_arg_t *arg = data;
    user_t *user = get_user_by_name(arg->name, save);

    if (!user)
        user = user_create(arg->name, save);
    client_send_success(client, arg->transaction);
    client_send_data(client, user->uuid, sizeof(uuid_t));
    client->logged = true;
    memcpy(client->uuid, user->uuid, sizeof(uuid_t));
}

void logout_cmd(client_t *client, save_t *save, void *data)
{
    logout_cmd_arg_t *arg = data;

    (void) save;
    if (!check_client_logged(client, arg->transaction))
        return;
    client->quit = true;
    client_send_success(client, arg->transaction);
}
