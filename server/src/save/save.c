/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** save
*/

#include <unistd.h>
#include <fcntl.h>
#include "teams.h"
#include "save.h"

static void save_users(list_t users, int fd)
{
    user_t *user;

    for (list_t list = users; list; list = list->next) {
        user = (user_t*) list->data;
        write(fd, user, sizeof(user_t));
        save_uuids(user->teams, fd);
        save_uuids(user->discussions, fd);
    }
}

static void save_discussions(list_t discussions, int fd)
{
    discussion_t *discussion;

    for (list_t list = discussions; list; list = list->next) {
        discussion = (discussion_t*) list->data;
        write(fd, discussion, sizeof(user_t));
        for (list_t msglist = discussion->messages;
        msglist; msglist = msglist->next)
            write(fd, msglist->data, sizeof(message_t));
    }
}

bool save_infos(save_t *save, char *path)
{
    int fd = open(path, O_WRONLY);

    if (fd == -1)
        return true;
    save_users(save->users, fd);
    save_discussions(save->discussions, fd);
    save_teams(save->teams, fd);
    return false;
}

void save_uuids(uuid_list_t uuids, int fd)
{
    uint len = node_len((list_t) uuids);

    write(fd, &len, sizeof(uint));
    for (uuid_list_t list = uuids; list; list = (uuid_list_t) list->next)
        write(fd, uuids->uuid, sizeof(uuid_t));
}
