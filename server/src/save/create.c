/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** create
*/

#include "teams.h"

user_t *user_create(char *name, save_t *save)
{
    user_t *user = safe_malloc(sizeof(user_t));

    uuid_generate(user->uuid);
    user->teams = NULL;
    user->teams_nb = 0;
    user->discussions = NULL;
    user->discussions_nb = 0;
    memset(user->name, 0, MAX_NAME_LENGTH);
    strncpy(user->name, name, MAX_NAME_LENGTH);
    push_back(&save->users, user);
    return user;
}

discussion_t *discussion_create(user_t *usr1, user_t *usr2, save_t *save)
{
    discussion_t *discussion = safe_malloc(sizeof(discussion_t));

    uuid_generate(discussion->uuid);
    memcpy(&discussion->uuid[0], usr1->uuid, sizeof(user_t));
    memcpy(&discussion->uuid[1], usr2->uuid, sizeof(user_t));
    discussion->messages = NULL;
    discussion->messages_nb = 0;
    push_back(&save->discussions, discussion);
    return discussion;
}

message_t *message_create(user_t *user, char *msg, discussion_t *discussion)
{
    message_t *message = safe_malloc(sizeof(message_t));

    uuid_generate(message->uuid);
    memcpy(message->user, user->uuid, sizeof(uuid_t));
    strncpy(message->msg, msg, MAX_BODY_LENGTH);
    message->time = time(NULL);
    push_back(&discussion->messages, message);
    discussion->messages_nb++;
    return message;
}
