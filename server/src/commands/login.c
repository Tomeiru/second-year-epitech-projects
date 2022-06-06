/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** login
*/

#include "teams.h"
#include "logging_server.h"
#include "events.h"

void login_cmd(client_t *client, server_t *server, void *data)
{
    login_cmd_arg_t *arg = data;
    user_t *user = get_user_by_name(arg->name, server->save);
    char uuid_str[36] = {0};

    if (!user) {
        user = user_create(arg->name, server->save);
        uuid_unparse(user->uuid, uuid_str);
        server_event_user_created(uuid_str, user->name);
        save_infos(server->save, SAVEFILE_PATH);
    }
    client_send_success(client, arg->transaction);
    client->logged = true;
    memcpy(client->uuid, user->uuid, sizeof(uuid_t));
    event_user_logged_in(server, user);
}

void logout_cmd(client_t *client, server_t *server, void *data)
{
    logout_cmd_arg_t *arg = data;
    user_t *user;

    (void) server;
    if (!check_client_logged(client, arg->transaction))
        return;
    user = get_user_by_uuid(client->uuid, server->save);
    if (!user) {
        puts("[ALERT] Client has an invalid UUID !");
        client_send_error(client, arg->transaction, ERROR_UNAUTHORIZED, NULL);
        return;
    }
    client->quit = true;
    event_user_logged_out(server, user);
    client_send_success(client, arg->transaction);
}
