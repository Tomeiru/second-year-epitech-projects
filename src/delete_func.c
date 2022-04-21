/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** delete_func
*/

#include "myftp.h"

void delete_absolute_path(char *args, fd_node_t *this)
{
    char *pos = strstr(args, this->home);

    if (pos != NULL && pos == args && !remove(args)) {
        dprintf(this->fd, "250 Successfully removed file\r\n");
        return;
    }
    dprintf(this->fd, "503 Couldn't remove %s\r\n", args);
}

void delete_relative_path(char *args, fd_node_t *this)
{
    char *cat = strdup(this->wd);
    char *filepath;
    char *pos;

    cat = realloc(cat, strlen(cat + strlen(args) + 2));
    cat = strcat(cat, "/");
    cat = strcat(cat, args);
    filepath = realpath(cat, NULL);
    free(cat);
    if ((pos = strstr(cat, this->home)) != NULL && pos == cat
    && !remove(filepath)) {
        free(cat);
        dprintf(this->fd, "250 Successfully removed file\r\n");
        free(filepath);
        return;
    }
    free(cat);
    dprintf(this->fd, "503 Couldn't remove %s\r\n", args);
    free(filepath);
}

int dele_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);

    if (!this->authentified) {
        dprintf(this->fd, "530 Not logged in!\r\n");
        return (0);
    }
    if (!strcmp(args, "\n") || strlen(args) == 2) {
        dprintf(this->fd, "501 DELE needs a path to work\r\n");
        return (0);
    }
    args[strlen(args) - 2] = '\0';
    if (args[0] == '/') {
        delete_absolute_path(args, this);
        return (0);
    }
    delete_relative_path(args, this);
    return (0);
}