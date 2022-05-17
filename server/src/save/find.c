/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** find
*/

#include <string.h>
#include "teams.h"

user_t *get_user_by_name(char *name, save_t *save)
{
    user_t *user;

    for (list_t list = save->users; list; list = list->next) {
        user = (user_t*) list->data;
        if (!strcmp(name, user->name))
            return user;
    }
    return NULL;
}

user_t *get_user_by_uuid(uuid_t uuid, save_t *save)
{
    user_t *user;

    for (list_t list = save->users; list; list = list->next) {
        user = (user_t*) list->data;
        if (!uuid_compare(uuid, user->uuid))
            return user;
    }
    return NULL;
}

team_t *get_team_by_uuid(uuid_t uuid, save_t *save)
{
    team_t *team;

    for (list_t list = save->users; list; list = list->next) {
        team = (team_t*) list->data;
        if (!uuid_compare(uuid, team->uuid))
            return team;
    }
    return NULL;
}

channel_t *get_channel_by_uuid(uuid_t uuid, team_t *team)
{
    channel_t *channel;

    for (list_t list = team->channels; list; list = list->next) {
        channel = (channel_t*) list->data;
        if (!uuid_compare(uuid, channel->uuid))
            return channel;
    }
    return NULL;
}

thread_t *get_thread_by_uuid(uuid_t uuid, channel_t *channel)
{
    thread_t *thread;

    for (list_t list = channel->threads; list; list = list->next) {
        thread = (thread_t*) list->data;
        if (!uuid_compare(uuid, thread->uuid))
            return thread;
    }
    return NULL;
}
