/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** utils
*/

#include "myftp.h"

void ftp_reset_fd(fd_set *set_read, fd_set *set_write)
{
    FD_ZERO(set_read);
    FD_ZERO(set_write);
}

void ftp_set_fd(int server_sock, fd_node_t *list, fd_set *set_read,
fd_set *set_write)
{
    FD_SET(server_sock, set_read);
    FD_SET(server_sock, set_write);
    for (fd_node_t *temp = list; temp; temp = temp->next) {
        FD_SET(temp->fd, set_read);
        FD_SET(temp->fd, set_write);
    }
}

int print_error(char *err)
{
    fprintf(stderr, "myftp: %s\n", err);
    return (84);
}

void free_and_set_command_to_null(fd_node_t *this)
{
    free(this->command);
    this->command = NULL;
}