/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** utils
*/

#include "myftp.h"

void ftp_reset_fd(fd_set *set_read)
{
    FD_ZERO(set_read);
}

void check_fd_max(int server_sock, fd_node_t *list, int *fd_max)
{
    int max = 0;

    if (server_sock > max)
        max = server_sock;
    for (fd_node_t *temp = list; temp; temp = temp->next) {
        if (temp->fd > max)
            max = temp->fd;
        if (temp->passive && temp->server_fd > max)
            max = temp->server_fd;
    }
    *fd_max = max + 1;
}

void ftp_set_fd(int server_sock, fd_node_t *list, fd_set *set_read, int *fd_max)
{
    FD_SET(server_sock, set_read);
    for (fd_node_t *temp = list; temp; temp = temp->next) {
        FD_SET(temp->fd, set_read);
        if (temp->passive == 1)
            FD_SET(temp->server_fd, set_read);
    }
    check_fd_max(server_sock, list, fd_max);
}

int print_error(char *err)
{
    fprintf(stderr, "myftp: %s\n", err);
    return (84);
}

void free_and_set_command_to_null(fd_node_t *this)
{
    if (this == NULL)
        return;
    free(this->command);
    this->command = NULL;
}