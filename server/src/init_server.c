/*
** EPITECH PROJECT, 2022
** teams
** File description:
** init_server
*/

#include "teams.h"

server_t *init_struct(int port, int opt)
{
    server_t *server = malloc(sizeof(server_t));
    struct sockaddr_in address;

    if ((server->fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return (NULL);
    }
    if (setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsocketopt");
        return (NULL);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    server->socket = address;
    if (bind(server->fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
            perror("bind failed");
            return (NULL);
    }
    return (server);
}

server_t *init_server(int port)
{
    server_t *server = init_struct(port, 1);

    if (!server)
        return (NULL);
    if (listen(server->fd, 3) < 0) {
        perror("listen");
        return (NULL);
    }
    return (server);
}