/*
** EPITECH PROJECT, 2022
** myteamsss
** File description:
** create
*/

#include "teams.h"

void client_team_created(client_t *client, team_t *team)
{
    client_send_data(client, team->uuid, sizeof(uuid_t));
    client_send_data(client, team->name, MAX_NAME_LENGTH);
    client_send_data(client, team->desc, MAX_DESCRIPTION_LENGTH);
}

void client_channel_created(client_t *client, channel_t *channel)
{
    client_send_data(client, channel->uuid, sizeof(uuid_t));
    client_send_data(client, channel->name, MAX_NAME_LENGTH);
    client_send_data(client, channel->desc, MAX_DESCRIPTION_LENGTH);
}

void client_thread_created(client_t *client, thread_t *thread)
{
    client_send_data(client, thread->uuid, sizeof(uuid_t));
    client_send_data(client, thread->user, sizeof(uuid_t));
    client_send_value(client, thread->timestamp, sizeof(time_t));
    client_send_data(client, thread->name, MAX_NAME_LENGTH);
    client_send_data(client, thread->msg, MAX_BODY_LENGTH);
}

void client_comment_created(client_t *client, team_t *team, thread_t *thread,
comment_t *comment)
{
    client_send_data(client, team->uuid, sizeof(uuid_t));
    client_send_data(client, thread->uuid, sizeof(uuid_t));
    client_send_value(client, comment->time, sizeof(time_t));
    client_send_data(client, comment->msg, MAX_BODY_LENGTH);
}