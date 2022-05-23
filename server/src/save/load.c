/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** load
*/

#include <unistd.h>
#include <fcntl.h>
#include "teams.h"
#include "save.h"

static void load_users(save_t *save, int fd)
{
    user_t *user;
    uint nb;
    char uuid[36];

    read(fd, &nb, sizeof(nb));
    for (uint i = 0; i < nb; i++) {
        user = safe_malloc(sizeof(user_t));
        read(fd, user, sizeof(user_t));
        user->teams = NULL;
        user->discussions = NULL;
        load_uuids(&user->teams, user->teams_nb, fd);
        load_uuids(&user->discussions, user->discussions_nb, fd);
        push_back(&save->users, user);
        uuid_unparse(user->uuid, uuid);
        server_event_user_loaded(uuid, user->name);
    }
}

static void load_discussions(save_t *save, int fd)
{
    discussion_t *discussion;
    message_t *message;
    uint nb;

    read(fd, &nb, sizeof(nb));
    for (uint i = 0; i < nb; i++) {
        discussion = safe_malloc(sizeof(discussion_t));
        discussion->messages = NULL;
        for (uint j = 0; j < discussion->messages_nb; j++) {
            message = safe_malloc(sizeof(message_t));
            read(fd, message, sizeof(message_t));
            push_back(&discussion->messages, message);
        }
        push_back(&save->discussions, discussion);
    }
}

void load_uuids(uuid_list_t *uuids, uint n, int fd)
{
    uuid_node_t *node;

    for (uint i = 0; i < n; i++) {
        node = safe_malloc(sizeof(uuid_node_t));
        read(fd, node->uuid, sizeof(uuid_t));
        push_node_back((list_t*) uuids, (node_t*) node);
    }
}

void load_infos(save_t *save, char *path)
{
    int fd = open(path, O_RDONLY);

    save->users = NULL;
    save->discussions = NULL;
    save->teams = NULL;
    if (fd == -1)
        return;
    load_users(save, fd);
    load_discussions(save, fd);
    load_teams(save, fd);
    close(fd);
}
