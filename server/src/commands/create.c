/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** create
*/

#include "teams.h"
#include "logging_server.h"
#include "macros.h"
#include "events.h"

void create_team_cmd(client_t *client, server_t *server, void *data)
{
    create_team_channel_cmd_arg_t *arg = data;
    team_t *team = get_team_by_name(arg->name, server->save);
    char team_uuid[36] = {0};
    char user_uuid[36] = {0};

    if (!check_client_logged(client, arg->transaction))
        return;
    if (team)
        return (client_send_error(client, arg->transaction, ERROR_ALREADY_EXISTS, NULL));
    team = team_create(arg->name, arg->desc, server->save);
    uuid_unparse(team->uuid, team_uuid);
    uuid_unparse(client->uuid, user_uuid);
    server_event_team_created(team_uuid, team->name, user_uuid);
    client_send_success(client, arg->transaction);
    client_team_created(client, team);
    event_team_created(server, team);
    save_infos(server->save, SAVEFILE_PATH);
}

void create_channel_cmd(client_t *client, server_t *server, void *data)
{
    create_team_channel_cmd_arg_t *arg = data;
    team_t *team;
    channel_t *channel;
    char team_uuid[36];
    char channel_uuid[36];

    if (!check_client_logged(client, arg->transaction)
    || !(team = GET_TEAM(client, arg, server->save))
    || !check_user_belongs_to_team(client, team, arg->transaction, true))
        return;
    if (get_channel_by_name(arg->name, team))
        return (client_send_error(client, arg->transaction,
        ERROR_ALREADY_EXISTS, NULL));
    channel = channel_create(arg->name, arg->desc, team);
    uuid_unparse(team->uuid, team_uuid);
    uuid_unparse(channel->uuid, channel_uuid);
    server_event_channel_created(team_uuid, channel_uuid, arg->name);
    client_send_success(client, arg->transaction);
    client_channel_created(client, channel);
    event_channel_created(server, team, channel);
    save_infos(server->save, SAVEFILE_PATH);
}

void create_thread_cmd(client_t *client, server_t *server, void *data)
{
    create_thread_cmd_arg_t *arg = data;
    team_t *team;
    channel_t *channel;
    thread_t *thread;
    char uuid[36 * 3];

    if (!check_client_logged(client, arg->transaction)
    || !(team = GET_TEAM(client, arg, server->save))
    || !check_user_belongs_to_team(client, team, arg->transaction, true)
    || !(channel = GET_CHANNEL(client, arg, team)))
        return;
    if ((thread = get_thread_by_title(arg->title, channel)))
        return (client_send_error(client, arg->transaction, ERROR_ALREADY_EXISTS, NULL));
    thread = thread_create(arg->title, arg->msg, client->uuid, channel);
    uuid_unparse(channel->uuid, uuid);
    uuid_unparse(thread->uuid, uuid + 36);
    uuid_unparse(client->uuid, uuid + 72);
    server_event_thread_created(uuid, uuid + 36,
    uuid + 72, arg->title, arg->msg);
    client_send_success(client, arg->transaction);
    client_thread_created(client, thread);
    event_thread_created(server, team, thread);
    save_infos(server->save, SAVEFILE_PATH);
}

void create_comment_cmd(client_t *client, server_t *server, void *data)
{
    create_comment_cmd_arg_t *arg = data;
    team_t *team;
    channel_t *channel;
    thread_t *thread;
    comment_t *comment;
    char thread_uuid[36];
    char user_uuid[36];

    if (!check_client_logged(client, arg->transaction)
    || !(team = GET_TEAM(client, arg, server->save))
    || !check_user_belongs_to_team(client, team, arg->transaction, true)
    || !(channel = GET_CHANNEL(client, arg, team))
    || !(thread = GET_THREAD(client, arg, channel)))
        return;
    comment = comment_create(arg->comment, client->uuid, thread);
    uuid_unparse(thread->uuid, thread_uuid);
    uuid_unparse(client->uuid, user_uuid);
    server_event_reply_created(thread_uuid, user_uuid, arg->comment);
    client_send_success(client, arg->transaction);
    client_comment_created(client, team, thread, comment);
    event_comment_created(server, team, thread, comment);
    save_infos(server->save, SAVEFILE_PATH);
}
