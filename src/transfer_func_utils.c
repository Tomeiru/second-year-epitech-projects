/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** command_func
*/

#include "myftp.h"

void close_correct_ft(fd_node_t *this)
{
    if (this->active) {
        this->active = 0;
        this->client_fd = 0;
    }
    if (this->passive) {
        this->passive = 0;
        this->server_fd = 0;
        this->pasv_connected = 0;
    }
}

char *rel_to_abs(char *args, fd_node_t *this)
{
    char *cat = strdup(this->wd);

    cat = realloc(cat, strlen(cat) + strlen(args) + 2);
    cat = strcat(cat, "/");
    cat = strcat(cat, args);
    return (cat);
}