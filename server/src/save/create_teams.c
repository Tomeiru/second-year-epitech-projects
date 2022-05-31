/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** create_teams
*/

#include "teams.h"

team_t *team_create(char *name, char *desc, save_t *save)
{
    team_t *team = safe_malloc(sizeof(team_t));

    uuid_generate(team->uuid);
    team->subscribers = NULL;
    team->channels_nb = 0;
    team->channels = NULL;
    team->channels_nb = 0;
    memset(team->name, 0, MAX_NAME_LENGTH);
    strncpy(team->name, name, MAX_NAME_LENGTH);
    memset(team->desc, 0, MAX_DESCRIPTION_LENGTH);
    strncpy(team->desc, desc, MAX_DESCRIPTION_LENGTH);
    push_back(&save->teams, team);
    return team;
}

channel_t *channel_create(char *name, char *desc, team_t *team)
{
    channel_t *channel = safe_malloc(sizeof(channel_t));

    uuid_generate(channel->uuid);
    channel->threads = NULL;
    channel->threads_nb = 0;
    memset(channel->name, 0, MAX_NAME_LENGTH);
    strncpy(channel->name, name, MAX_NAME_LENGTH);
    memset(channel->desc, 0, MAX_DESCRIPTION_LENGTH);
    strncpy(channel->desc, desc, MAX_DESCRIPTION_LENGTH);
    push_back(&team->channels, channel);
    team->channels_nb++;
    return channel;
}

thread_t *thread_create(char *name,
char *msg, uuid_t sender, channel_t *channel)
{
    thread_t *thread = safe_malloc(sizeof(thread_t));

    uuid_generate(thread->uuid);
    thread->comments = NULL;
    thread->comments_nb = 0;
    memcpy(thread->user, sender, sizeof(uuid_t));
    memset(thread->name, 0, MAX_NAME_LENGTH);
    strncpy(thread->name, name, MAX_NAME_LENGTH);
    memset(thread->msg, 0, MAX_BODY_LENGTH);
    strncpy(thread->msg, msg, MAX_BODY_LENGTH);
    push_back(&channel->threads, thread);
    channel->threads_nb++;
    return thread;
}

comment_t *comment_create(char *msg, uuid_t sender, thread_t *thread)
{
    comment_t *comment = safe_malloc(sizeof(comment_t));

    uuid_generate(comment->uuid);
    memcpy(comment->user, sender, sizeof(uuid_t));
    memset(comment->msg, 0, MAX_BODY_LENGTH);
    strncpy(comment->msg, msg, MAX_BODY_LENGTH);
    comment->time = time(NULL);
    push_back(&thread->comments, comment);
    thread->comments_nb++;
    return comment;
}
