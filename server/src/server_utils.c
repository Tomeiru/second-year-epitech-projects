/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** server_utils
*/

#include "teams.h"

bool accept_new_clients(int socket, list_t *list)
{
    socklen_t addr_size = sizeof(struct sockaddr);
    struct sockaddr_in addr_in;
    client_t *client;
    int fd = accept(socket, (sockaddr_t*) &addr_in, &addr_size);

    if (fd == -1)
        return true;
    client = client_create(fd, &addr_in, list);
    if (!client)
        return true;
    return false;
}

int set_fd(fd_set *readfds, server_t *server, list_t list)
{
    int max_fd = server->fd + 1;
    client_t *client;

    FD_ZERO(readfds);
    FD_SET(server->fd, readfds);
    for (node_t *node = list; node; node = node->next) {
        client = (client_t*) node->data;
        FD_SET(client->fd, readfds);
        if (client->fd > max_fd)
            max_fd = client->fd;
    }
    return (max_fd);
}
