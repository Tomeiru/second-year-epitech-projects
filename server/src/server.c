/*
** EPITECH PROJECT, 2022
** teams
** File description:
** init_server
*/

#include "teams.h"

server_t *init_server(int port)
{
    server_t *server = init_serv_struct(port, 1);

    if (!server)
        return (NULL);
    load_infos(server->save, "./teams.dat");
    if (listen(server->fd, 3) < 0) {
        puts("listen");
        return (NULL);
    }
    return (server);
}

server_t *init_serv_struct(int port, int opt)
{
    server_t *server = safe_malloc(sizeof(server_t));
    struct sockaddr_in address;

    if ((server->fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        puts("socket failed");
        return (NULL);
    }
    if (setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        puts("setsocketopt");
        return (NULL);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    server->socket = address;
    if (bind(server->fd, (struct sockaddr*) &address, sizeof(address)) < 0) {
        puts("bind failed");
        return (NULL);
    }
    return (server);
}

int start_server(int port)
{
    server_t *server = init_server(port);
    list_t client_list = NULL;
    fd_set readfds;
    int max_fd = 0;

    if (!server)
        return (84);
    while (1) {
        max_fd = set_fd(&readfds, server, client_list);
        server_update(server, &client_list, &readfds, max_fd);
    }
}

void server_update(server_t *srv, list_t *list, fd_set *readfds, int max)
{
    int activity = select(max + 1, readfds, NULL, NULL, NULL);
    client_t *client;

    if ((activity < 0) && (errno != EINTR))
        puts("select error");
    if (FD_ISSET(srv->fd, readfds))
        accept_new_clients(srv->fd, list);
    for (node_t *node = *list; node; node = node->next) {
        client = (client_t*) node->data;
        if (!FD_ISSET(client->fd, readfds))
            continue;
        client_update(client, srv);
    }
    return;
}
