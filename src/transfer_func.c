/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** command_func
*/

#include "myftp.h"

int pasv_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    int port = 0;

    if (!this->authentified) {
        dprintf(this->fd, "530 Not logged in!\r\n");
        return (0);
    }
    if (!strcmp(args, "\n")) {
        this->passive = 1;
        this->server_fd = start_server(-1);
        getsockname(this->server_fd, (struct sockaddr *)&addr, &len);
        port = ntohs(addr.sin_port);
        dprintf(this->fd, "227 (127,0,0,1,%i,%i)\r\n", port / 1000,
        port % 1000);
        return (0);
    }
    dprintf(this->fd, "501 PWD doesn't take any argument\r\n");
    return (0);
}

int port_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);

    if (!this->authentified) {
        dprintf(this->fd, "530 Not logged in!\r\n");
        return (0);
    }
    this->active = 1;
    UNUSED(args);
    return (0);
}

int retr_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);

    UNUSED(args);
    UNUSED(this);
    return (0);
}

int stor_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);

    UNUSED(args);
    UNUSED(this);
    return (0);
}

int list_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);

    UNUSED(args);
    UNUSED(this);
    return (0);
}