/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** load_teams
*/

#include "teams.h"
#include "save.h"

static void load_comments(thread_t *thread, int fd)
{
    comment_t *comment;

    for (uint i = 0; i < thread->comments_nb; i++) {
        comment = safe_malloc(sizeof(comment_t));
        read(fd, comment, sizeof(comment_t));
        push_back(&thread->comments, comment);
    }
}

static void load_threads(channel_t *channel, int fd)
{
    thread_t *thread;

    for (uint i = 0; i < channel->threads_nb; i++) {
        thread = safe_malloc(sizeof(thread_t));
        read(fd, thread, sizeof(thread));
        thread->comments = NULL;
        load_comments(thread, fd);
        push_back(&channel->threads, thread);
    }
}

static void load_channels(team_t *team, int fd)
{
    channel_t *channel;

    for (uint i = 0; i < team->channels_nb; i++) {
        channel = safe_malloc(sizeof(channel));
        read(fd, channel, sizeof(channel_t));
        channel->threads = NULL;
        load_threads(channel, fd);
        push_back(&team->channels, channel);
    }
}

void load_teams(save_t *save, int fd)
{
    team_t *team;
    uint nb;

    read(fd, &nb, sizeof(nb));
    for (uint i = 0; i < nb; i++) {
        team = safe_malloc(sizeof(team_t));
        read(fd, team, sizeof(team_t));
        team->subscribers = NULL;
        team->channels = NULL;
        load_uuids(&team->subscribers, team->subscribers_nb, fd);
        load_channels(team, fd);
        push_back(&save->teams, team);
    }
}
