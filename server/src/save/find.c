/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** find
*/

#include <string.h>
#include "teams.h"

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

discussion_t *get_discussion_by_user_uuids(uuid_t uuid1,
uuid_t uuid2, save_t *save)
{
    discussion_t *discussion;

    for (list_t list = save->discussions; list; list = list->next) {
        discussion = (discussion_t*) list->data;
        if ((!uuid_compare(discussion->users[0], uuid1)
        && !uuid_compare(discussion->users[1], uuid2))
        || (!uuid_compare(discussion->users[0], uuid2)
        && !uuid_compare(discussion->users[1], uuid1)))
            return discussion;
    }
    return NULL;
}
