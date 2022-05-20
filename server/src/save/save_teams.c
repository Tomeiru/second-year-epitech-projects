/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** save_teams
*/

#include "teams.h"
#include "save.h"

static void save_comments(list_t comments, int fd)
{
    comment_t *comment;

    for (list_t list = comments; list; list = list->next) {
        comment = (comment_t*) list->data;
        write(fd, comment, sizeof(comment_t));
    }
}

static void save_threads(list_t threads, int fd)
{
    thread_t *thread;

    for (list_t list = threads; list; list = list->next) {
        thread = (thread_t*) list->data;
        write(fd, thread, sizeof(thread_t));
        save_comments(thread->comments, fd);
    }
}

static void save_channels(list_t channels, int fd)
{
    channel_t *channel;

    for (list_t list = channels; list; list = list->next) {
        channel = (channel_t*) list->data;
        write(fd, channel, sizeof(channel_t));
        save_threads(channel->threads, fd);
    }
}

void save_teams(list_t teams, int fd)
{
    uint len = node_len(teams);
    team_t *team;

    write(fd, &len, sizeof(uint));
    for (list_t list = teams; list; list = list->next) {
        team = (team_t*) list->data;
        write(fd, team, sizeof(team_t));
        save_uuids(team->subscribers, fd);
        save_channels(team->channels, fd);
    }
}
