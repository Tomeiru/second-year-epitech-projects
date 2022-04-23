/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** connect_func
*/

#include "myftp.h"

int user_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);

    if (this->authentified) {
        dprintf(this->fd, "530 Already authentificated\r\n");
        return (0);
    }
    if (strcmp(args, "\n")) {
        dprintf(this->fd, "331 Username identified, need a password\r\n");
        this->uname_entered = 1;
        this->uname = strdup(args);
        return (0);
    }
    dprintf(this->fd, "550 Username provided is not handled or wrongly form\
atted\r\n");
    return (0);
}

int pass_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);

    if (this->authentified) {
        dprintf(this->fd, "530 Already authentificated\r\n");
        return (0);
    }
    if (!this->uname_entered) {
        dprintf(this->fd, "332 Username not entered (see USER in HELP)\r\n");
        return (0);
    }
    if (!strcmp(args, "\r\n") && !strcmp(this->uname, "Anonymous\r\n")) {
        dprintf(this->fd, "230 User successfully logged in. Welcome Anonymous!\
\r\n");
        this->authentified = 1;
        return (0);
    }
    dprintf(this->fd, "530 Wrong password\r\n");
    return (0);
}

int quit_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);

    if (!strcmp(args, "\n")) {
        dprintf(this->fd, "221 Connection closed\r\n");
        close(this->fd);
        list_remove_index(list, index);
        return (2);
    }
    dprintf(this->fd, "550 QUIT doesn't take any argument\r\n");
    return (0);
}