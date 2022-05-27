/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** create
*/

#include "teams.h"
#include "logging_server.h"
#include "macros.h"

// TODO : check name
void create_team_cmd(client_t *client, server_t *server, void *data)
{
    create_team_cmd_arg_t *arg = data;
    team_t *team;
    char team_uuid[36];
    char user_uuid[36];

    if (!check_client_logged(client, arg->transaction))
        return;
    team = team_create(arg->name, arg->desc, server->save);
    uuid_unparse(team->uuid, team_uuid);
    uuid_unparse(client->uuid, user_uuid);
    server_event_team_created(team_uuid, team->name, user_uuid);
    client_send_success(client, arg->transaction);
    client_send_data(client, team->uuid, sizeof(uuid_t));
}

// TODO : check name
void create_channel_cmd(client_t *client, server_t *server, void *data)
{
    create_channel_cmd_arg_t *arg = data;
    team_t *team;
    channel_t *channel;
    char team_uuid[36];
    char channel_uuid[36];

    if (!check_client_logged(client, arg->transaction)
    || !(team = GET_TEAM(client, arg, server->save)))
        return;
    channel = channel_create(arg->name, arg->desc, team);
    uuid_unparse(team->uuid, team_uuid);
    uuid_unparse(channel->uuid, channel_uuid);
    server_event_channel_created(team_uuid, channel_uuid, arg->name);
    client_send_success(client, arg->transaction);
    client_send_data(client, channel->uuid, sizeof(uuid_t));
}

void create_thread_cmd(client_t *client, server_t *server, void *data)
{
    create_thread_cmd_arg_t *arg = data;
    team_t *team;
    channel_t *channel;
    thread_t *thread;
    char channel_uuid[36];
    char thread_uuid[36];
    char user_uuid[36];

    if (!check_client_logged(client, arg->transaction)
    || !(team = GET_TEAM(client, arg, server->save))
    || !(channel = GET_CHANNEL(client, arg, team)))
        return;
    thread = thread_create(arg->title, arg->msg, client->uuid, channel);
    uuid_unparse(channel->uuid, channel_uuid);
    uuid_unparse(thread->uuid, thread_uuid);
    uuid_unparse(client->uuid, user_uuid);
    server_event_thread_created(channel_uuid,
    thread_uuid, user_uuid, arg->title, arg->msg);
    client_send_success(client, arg->transaction);
    client_send_data(client, thread->uuid, sizeof(uuid_t));
}

// TODO : TIMESTAMP
void create_comment_cmd(client_t *client, server_t *server, void *data)
{
    create_comment_cmd_arg_t *arg = data;
    team_t *team;
    channel_t *channel;
    thread_t *thread;
    char thread_uuid[36];
    char user_uuid[36];

    if (!check_client_logged(client, arg->transaction)
    || !(team = GET_TEAM(client, arg, server->save))
    || !(channel = GET_CHANNEL(client, arg, team))
    || !(thread = GET_THREAD(client, arg, channel)))
        return;
    comment_create(arg->comment, client->uuid, thread);
    uuid_unparse(thread->uuid, thread_uuid);
    uuid_unparse(client->uuid, user_uuid);
    server_event_reply_created(thread_uuid, user_uuid, arg->comment);
    client_send_success(client, arg->transaction);
}