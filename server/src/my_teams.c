/*
** EPITECH PROJECT, 2022
** teams
** File description:
** my_teams
*/

#include "teams.h"


void client_adding(server_t *srv, node_t **client_l)
{
    client_t *tmp = malloc(sizeof(client_t));
    int len = sizeof(tmp->socket);

    tmp->fd = accept(srv->fd, (struct sockaddr *)&tmp->socket,
    (socklen_t *)&(len));
    if (tmp->fd < 0) {
        perror("accept");
        exit(84);
    }
    tmp->ip = inet_ntoa(tmp->socket.sin_addr);
    tmp->port = ntohs(tmp->socket.sin_port);
    tmp->request = malloc(sizeof(command_t));
    push_back(client_l, (void *)tmp);
    printf("Connection from %s with port %d\n", tmp->ip, tmp->port);
    write(tmp->fd, "client connected\r\n", 19);
}

void client_managing(server_t *srv, node_t **client_l, fd_set readfds, int max)
{
    int valread = 0;
    client_t *tmp;
    node_t *camera;
    int size = 0;
    int activity = select (max + 1, &readfds, NULL, NULL, NULL);

    if ((activity < 0) && (errno != EINTR))
        printf("select error");
    if (FD_ISSET(srv->fd, &readfds))
        client_adding(srv, client_l);
    camera = *client_l;
    size = node_len(&camera);
    for (int i = 0; i < size; i++) {
        tmp = (client_t *)(camera)->data;
        if (FD_ISSET(tmp->fd, &readfds)) {
            if ((valread = read(tmp->fd, tmp->request, 1024)) == 0) {
                delete_client(tmp, client_l, i);
            } else {
                if (strncmp(tmp->request, "Logout", 4) ==    0) {
                    delete_client(tmp, client_l, i);
                    return;
                }
                command_handler(str_warray(tmp->request, " \n\r\t"), tmp, srv);
            }
        }
        camera = camera->next;
    }
    return;
}

int set_fd(fd_set *readfds, server_t *server, node_t **client_l)
{
    int max_fd = server->fd + 1;
    int size = 0;
    node_t *camera = NULL;
    client_t *tmp;

    FD_ZERO(readfds);
    camera = *client_l;
    FD_SET(server->fd, readfds);
    if (node_len(&camera) == 0)
        return (max_fd);
    size = node_len(&camera);
    for (int i = 0; i < size; i++) {
        tmp = (client_t *)(camera)->data;
        if (tmp->fd > 0)
            FD_SET(tmp->fd, readfds);
        if (tmp->fd > max_fd)
            max_fd = tmp->fd;
        camera = camera->next;
    }
    return (max_fd);
}

int starting_server(int port)
{
    server_t *server = init_server(port);
    node_t *client_list = NULL;
    fd_set readfds;
    int max_fd = 0;

    if (!server)
        return (84);
    while (1) {
        max_fd = set_fd(&readfds, server, &client_list);
        client_managing(server, &client_list, readfds, max_fd);
    }
}

int my_teams(int ac, char **av)
{
    if (ac == 2 && strcmp("-help", av[1]) == 0) {
        printf("USAGE: ./myteams_server port\n\n");
        printf("       port is the port number on which the server socket");
        printf(" listens.\n");
        return (0);
    } else if (ac != 2 || is_not_number(av[1]))
        return (84);
    return (starting_server(atoi(av[1])));
}