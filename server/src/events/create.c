/*
** EPITECH PROJECT, 2022
** myteamss
** File description:
** create
*/

#include "teams.h"
#include "cmd_ids.h"

void event_team_created(server_t *server, team_t *team)
{
    client_t *client;

    for (list_t list = server->clients; list; list = list->next) {
        client = (client_t *)list->data;
        if (!client->logged)
            continue;
        client_send_value(client, EVENT_TEAM_CREATED_ID, sizeof(command_id_t));
        client_send_data(client, team->uuid, sizeof(uuid_t));
        client_send_data(client, team->name, MAX_NAME_LENGTH);
        client_send_data(client, team->desc, MAX_DESCRIPTION_LENGTH);
    }
}

void event_channel_created(server_t *server, team_t *team, channel_t *channel)
{
    client_t *client;

    for (list_t list = server->clients; list; list = list->next) {
        client = (client_t *)list->data;
        if (!check_user_belongs_to_team(client, team, 0, false))
            continue;
        client_send_value(client, EVENT_CHANNEL_CREATED_ID, sizeof(command_id_t));
        client_send_data(client, channel->uuid, sizeof(uuid_t));
        client_send_data(client, channel->name, MAX_NAME_LENGTH);
        client_send_data(client, channel->desc, MAX_DESCRIPTION_LENGTH);
    }
}

void event_thread_created(server_t *server, team_t *team, thread_t *thread)
{
    client_t *client;

    for (list_t list = server->clients; list; list = list->next) {
        client = (client_t *)list->data;
        if (!check_user_belongs_to_team(client, team, 0, false))
            continue;
        client_send_value(client, EVENT_THREAD_CREATED_ID, sizeof(command_id_t));
        client_send_data(client, thread->uuid, sizeof(uuid_t));
        client_send_data(client, client->uuid, sizeof(uuid_t));
        client_send_value(client, thread->timestamp, sizeof(time_t));
        client_send_data(client, thread->name, MAX_NAME_LENGTH);
        client_send_data(client, thread->msg, MAX_BODY_LENGTH);
    }
}

void event_comment_created(server_t *server, team_t *team, thread_t *thread, comment_t *comment)
{
    client_t *client;

    for (list_t list = server->clients; list; list = list->next) {
        client = (client_t *)list->data;
        if (!check_user_belongs_to_team(client, team, 0, false))
            continue;
        client_send_value(client, EVENT_REPLY_CREATED_ID, sizeof(command_id_t));
        client_send_data(client, team->uuid, sizeof(uuid_t));
        client_send_data(client, thread->uuid, sizeof(uuid_t));
        client_send_data(client, comment->user, sizeof(uuid_t));
        client_send_data(client, comment->msg, MAX_BODY_LENGTH);
    }
}