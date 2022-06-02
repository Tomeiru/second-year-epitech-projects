/*
** EPITECH PROJECT, 2022
** myteamsss
** File description:
** info
*/

#include "teams.h"
#include "logging_server.h"
#include "macros.h"
#include "events.h"

void info_user_cmd(client_t *client, server_t *server, void *data)
{
    info_cmd_arg_t *arg = data;
    user_t *user;

    if (!check_client_logged(client, arg->transaction)
    || !(user = get_user_or_error(client, client->uuid, server->save,
    arg->transaction)))
        return;
    client_send_success(client, arg->transaction);
    client_send_data(client, user->uuid, sizeof(uuid_t));
    client_send_data(client, user->name, MAX_NAME_LENGTH);
    if (get_connected_client(user->uuid, server))
        client_send_value(client, (size_t)1, sizeof(size_t));
    else
        client_send_value(client, (size_t)0, sizeof(size_t));
}

void info_team_cmd(client_t *client, server_t *server, void *data)
{
    info_cmd_arg_t *arg = data;
    team_t *team;

    if (!check_client_logged(client, arg->transaction)
    || !(team = GET_TEAM(client, arg, server->save))
    || !check_user_belongs_to_team(client, team, arg->transaction, true))
        return;
    client_send_success(client, arg->transaction);
    client_team_created(client, team);
}

void info_channel_cmd(client_t *client, server_t *server, void *data)
{
    create_thread_cmd_arg_t *arg = data;
    team_t *team;
    channel_t *channel;

    if (!check_client_logged(client, arg->transaction)
    || !(team = GET_TEAM(client, arg, server->save))
    || !check_user_belongs_to_team(client, team, arg->transaction, true)
    || !(channel = GET_CHANNEL(client, arg, team)))
        return;
    client_send_success(client, arg->transaction);
    client_channel_created(client, channel);
}

void info_thread_cmd(client_t *client, server_t *server, void *data)
{
    create_comment_cmd_arg_t *arg = data;
    team_t *team;
    channel_t *channel;
    thread_t *thread;

    if (!check_client_logged(client, arg->transaction)
    || !(team = GET_TEAM(client, arg, server->save))
    || !check_user_belongs_to_team(client, team, arg->transaction, true)
    || !(channel = GET_CHANNEL(client, arg, team))
    || !(thread = GET_THREAD(client, arg, channel)))
        return;
    client_send_success(client, arg->transaction);
    client_thread_created(client, thread);
}
