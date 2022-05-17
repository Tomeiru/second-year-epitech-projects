/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** create
*/

#include "teams.h"
#include "logging_server.h"

// TODO : check name
void create_team_cmd(client_t *client, save_t *save, void *data)
{
    create_team_cmd_arg_t *arg = data;
    team_t *team;
    char team_uuid[36];
    char user_uuid[36];

    if (!client_check_logged(client))
        return;
    team = team_create(arg->name, arg->desc, save);
    uuid_unparse(team->uuid, team_uuid);
    uuid_unparse(client->uuid, user_uuid);
    server_event_team_created(team_uuid, team->name, user_uuid);
}

// TODO : check name
void create_channel_cmd(client_t *client, save_t *save, void *data)
{
    create_channel_cmd_arg_t *arg = data;
    team_t *team;
    channel_t *channel;
    char team_uuid[36];
    char channel_uuid[36];

    if (!client_check_logged(client)
    || !(team = get_team_by_uuid(arg->team_uuid, save)))
        return;
    channel = channel_create(arg->name, arg->desc, team);
    uuid_unparse(team->uuid, team_uuid);
    uuid_unparse(channel->uuid, channel_uuid);
    server_event_channel_created(team_uuid, channel_uuid, arg->name);
}

void create_thread_cmd(client_t *client, save_t *save, void *data)
{
    create_thread_cmd_arg_t *arg = data;
    team_t *team;
    channel_t *channel;
    thread_t *thread;
    char channel_uuid[36];
    char thread_uuid[36];
    char user_uuid[36];

    if (!client_check_logged(client)
    || !(team = get_team_by_uuid(arg->team_uuid, save))
    || !(channel = get_channel_by_uuid(arg->channel_uuid, team)))
        return;
    thread = thread_create(arg->title, arg->msg, client->uuid, channel);
    uuid_unparse(channel->uuid, channel_uuid);
    uuid_unparse(thread->uuid, thread_uuid);
    uuid_unparse(client->uuid, user_uuid);
    server_event_thread_created(channel_uuid,
    thread_uuid, user_uuid, arg->title, arg->msg);
}

void create_comment_cmd(client_t *client, save_t *save, void *data)
{
    create_comment_cmd_arg_t *arg = data;
    team_t *team;
    channel_t *channel;
    thread_t *thread;
    char thread_uuid[36];
    char user_uuid[36];

    if (!client_check_logged(client)
    || !(team = get_team_by_uuid(arg->team_uuid, save))
    || !(channel = get_channel_by_uuid(arg->channel_uuid, team))
    || !(thread = get_thread_by_uuid(arg->thread_uuid, channel)))
        return;
    comment_create(arg->comment, client->uuid, thread);
    uuid_unparse(thread->uuid, thread_uuid);
    uuid_unparse(client->uuid, user_uuid);
    server_event_reply_created(thread_uuid, user_uuid, arg->comment);
}
