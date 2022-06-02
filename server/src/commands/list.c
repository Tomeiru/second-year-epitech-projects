/*
** EPITECH PROJECT, 2022
** myteamsss
** File description:
** list
*/

#include "teams.h"
#include "logging_server.h"
#include "macros.h"
#include "events.h"

void list_team_cmd(client_t *client, server_t *server, void *data)
{
    list_cmd_arg_t *arg = data;
    size_t len = (size_t)node_len(server->save->teams);
    team_t *team;

    if (!check_client_logged(client, arg->transaction))
        return;
    client_send_success(client, arg->transaction);
    client_send_value(client, len, sizeof(size_t));
    for (list_t list = server->save->teams; list; list = list->next) {
        team = (team_t *)list->data;
        client_send_data(client, team->uuid, sizeof(uuid_t));
        client_send_data(client, team->name, MAX_NAME_LENGTH);
        client_send_data(client, team->desc, MAX_DESCRIPTION_LENGTH);
    }
}

void list_channel_cmd(client_t *client, server_t *server, void *data)
{
    list_cmd_arg_t *arg = data;
    team_t *team;
    channel_t *channel;

    if (!check_client_logged(client, arg->transaction)
    || !(team = GET_TEAM(client, arg, server->save))
    || !check_user_belongs_to_team(client, team, arg->transaction, true))
        return;
    client_send_success(client, arg->transaction);
    client_send_value(client, team->channels_nb, sizeof(uint));
    for (list_t list = team->channels; list; list = list->next) {
        channel = (channel_t *)list->data;
        client_send_data(client, channel->uuid, sizeof(uuid_t));
        client_send_data(client, channel->name, MAX_NAME_LENGTH);
        client_send_data(client, channel->desc, MAX_DESCRIPTION_LENGTH);
    }
}

void list_thread_cmd(client_t *client, server_t *server, void *data)
{
    list_cmd_arg_t *arg = data;
    team_t *team;
    channel_t *channel;
    thread_t *thread;

    if (!check_client_logged(client, arg->transaction)
    || !(team = GET_TEAM(client, arg, server->save))
    || !check_user_belongs_to_team(client, team, arg->transaction, true)
    || !(channel = GET_CHANNEL(client, arg, team)))
        return;
    client_send_success(client, arg->transaction);
    client_send_value(client, channel->threads_nb, sizeof(uint));
    for (list_t list = channel->threads; list; list = list->next) {
        thread = (thread_t *)list->data;
        client_send_data(client, thread->uuid, sizeof(uuid_t));
        client_send_data(client, thread->user, sizeof(uuid_t));
        client_send_value(client, thread->timestamp, sizeof(time_t));
        client_send_data(client, thread->name, MAX_NAME_LENGTH);
        client_send_data(client, thread->msg, MAX_BODY_LENGTH);
    }
}

void list_comment_cmd(client_t *client, server_t *server, void *data)
{
    list_cmd_arg_t *arg = data;
    team_t *team;
    channel_t *channel;
    thread_t *thread;
    comment_t *comment;

    if (!check_client_logged(client, arg->transaction)
    || !(team = GET_TEAM(client, arg, server->save))
    || !check_user_belongs_to_team(client, team, arg->transaction, true)
    || !(channel = GET_CHANNEL(client, arg, team))
    || !(thread = GET_THREAD(client, arg, channel)))
        return;
    client_send_success(client, arg->transaction);
    client_send_value(client, thread->comments_nb, sizeof(uint));
    for (list_t list = thread->comments; list; list = list->next) {
        comment = (comment_t *)list->data;
        client_send_data(client, comment->uuid, sizeof(uuid_t));
        client_send_data(client, comment->user, sizeof(uuid_t));
        client_send_value(client, comment->time, sizeof(time_t));
        client_send_data(client, comment->msg, MAX_BODY_LENGTH);
    }
}
