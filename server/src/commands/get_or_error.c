/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** get_or_error
*/

#include "teams.h"

team_t *get_team_or_error(client_t *client,
uuid_t uuid, save_t *save, uint64_t transaction)
{
    team_t *team = get_team_by_uuid(uuid, save);

    if (!team)
        client_send_error(client, transaction, ERROR_UNKNOWN_TEAM, &uuid);
    return team;
}

channel_t *get_channel_or_error(client_t *client,
uuid_t uuid, team_t *team, uint64_t transaction)
{
    channel_t *channel = get_channel_by_uuid(uuid, team);

    if (!channel)
        client_send_error(client, transaction, ERROR_UNKNOWN_CHANNEL, &uuid);
    return channel;
}

thread_t *get_thread_or_error(client_t *client,
uuid_t uuid, channel_t *channel, uint64_t transaction)
{
    thread_t *thread = get_thread_by_uuid(uuid, channel);

    if (!thread)
        client_send_error(client, transaction, ERROR_UNKNOWN_THREAD, &uuid);
    return thread;
}

user_t *get_user_or_error(client_t *client,
uuid_t uuid, save_t *save, uint64_t transaction)
{
    user_t *user = get_user_by_uuid(uuid, save);

    if (!user)
        client_send_error(client, transaction, ERROR_UNKNOWN_USER, &uuid);
    return user;
}
