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
    load_infos(server->save, SAVEFILE_PATH);
    if (listen(server->fd, 3) < 0) {
        puts("listen");
        return (NULL);
    }
    return (server);
}

server_t *init_serv_struct(int port, int opt)
{
    server_t *server = safe_malloc(sizeof(server_t));
    sockaddr_in_t address = { .sin_family = AF_INET,
    .sin_addr.s_addr = INADDR_ANY, .sin_port = htons(port)};

    server->save = safe_malloc(sizeof(save_t));
    if ((server->fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        puts("socket failed");
        return (NULL);
    }
    if (setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        puts("setsocketopt");
        return (NULL);
    }
    memcpy(&server->socket, &address, sizeof(sockaddr_in_t));
    if (bind(server->fd, (struct sockaddr*) &address, sizeof(address)) < 0) {
        puts("bind failed");
        return (NULL);
    }
    server->clients = NULL;
    return (server);
}

int start_server(int port)
{
    server_t *server = init_server(port);
    fd_set readfds;
    int max_fd = 0;

    if (!server)
        return (84);
    while (1) {
        max_fd = set_fd(&readfds, server);
        server_update(server, &readfds, max_fd);
    }
    save_infos(server->save, "./teams.dat");
    save_destroy(server->save);
    free(server);
}

void server_update(server_t *srv, fd_set *readfds, int max)
{
    int activity = select(max + 1, readfds, NULL, NULL, NULL);
    client_t *client;

    if ((activity < 0) && (errno != EINTR))
        puts("select error");
    if (FD_ISSET(srv->fd, readfds))
        accept_new_clients(srv);
    for (node_t *node = srv->clients; node; node = node->next) {
        client = (client_t*) node->data;
        if (!FD_ISSET(client->fd, readfds))
            continue;
        client_update(client, srv);
    }
    disconnect_clients(srv);
}

void disconnect_clients(server_t *srv)
{
    list_t prev = NULL;
    list_t next;
    client_t *client;

    for (list_t list = srv->clients; list; list = next) {
        next = list->next;
        client = (client_t*) list->data;
        if (!client->quit)
            continue;
        client_delete(client);
        free(list);
        if (prev)
            prev->next = next;
        else
            srv->clients = next;
    }
}
